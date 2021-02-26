use super::record::Record;
use std::{convert, fmt, mem, ops, slice};

/// Contains common stack sizes.
#[repr(usize)]
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum CommonStackSize {
    /// 8KB stack -> ((1024 * 8) / 4) entries, sizeof(Record) == 4
    Small8KB = 1024 * 8,

    Small32KB = 1024 * 32,

    /// 32KB stack -> ((1024 * 32) / 4) entries, sizeof(Record) == 4
    Small64KB = 1024 * 64,

    /// 128KB stack -> ((1024 * 128) / 4) entries, sizeof(Record) == 4
    Medium128KB = 1024 * 128,

    /// 256KB stack -> ((1024 * 256) / 4) entries, sizeof(Record) == 4
    Medium256KB = 1024 * 256,

    /// 512KB stack -> ((1024 * 512) / 4) entries, sizeof(Record) == 4
    Medium512KB = 1024 * 512,

    /// 1KB stack -> ((1024 * 1024) / 4) entries, sizeof(Record) == 4
    Large1MB = 1024 * 1024,

    /// 4MB stack -> ((1024 * 1024 * 4) / 4) entries, sizeof(Record) == 4
    Large4MB = 1024 * 1024 * 4,

    /// 8MB stack -> ((1024 * 1024 * 48 / 4) entries, sizeof(Record) == 4
    Large8MB = 1024 * 1024 * 8,
}

impl CommonStackSize {
    /// Returns the amount of bytes by the current enumerator.
    #[inline]
    pub fn as_bytes(&self) -> usize {
        *self as _
    }

    /// Returns the amount of bits by the current enumerator.
    #[inline]
    pub fn as_bits(&self) -> usize {
        (*self as usize) * 8
    }
}

impl convert::From<CommonStackSize> for usize {
    #[inline]
    fn from(x: CommonStackSize) -> Self {
        x as Self
    }
}

/// Represents a mutable, fixed size heap-allocated stack.
#[derive(Clone)]
pub struct Stack {
    buf: Box<[Record]>,
    sp: usize,
}

impl Stack {
    /// Creates a new instance with a specified amount of records.
    pub fn with_length(len: usize) -> Self {
        assert_ne!(len, 0);
        Self {
            // Plus 1 because the first stack element is preserved.
            buf: vec![Record::from(0); len + 1].into_boxed_slice(),
            sp: 0,
        }
    }

    /// Creates a new instance with a specified size in bytes.
    /// Panics if the byte size is 0 or not a multiple of (sizeof(Record) == 4)
    pub fn with_byte_size(size: usize) -> Self {
        assert_ne!(size, 0);
        assert_eq!(size % mem::size_of::<Record>(), 0);
        Self {
            buf: vec![Record::from(0); size / mem::size_of::<Record>()].into_boxed_slice(),
            sp: 0,
        }
    }

    /// Creates a new instance with a byte size specified in the enum.
    pub fn with_common_size(size: CommonStackSize) -> Self {
        Self::with_byte_size(size as usize)
    }
}

impl Stack {
    /// Returns the number of records the buffer can hold.
    #[inline(always)]
    pub fn length(&self) -> usize {
        self.buf.len()
    }

    /// Returns true if there are no records, else false. (sp == 0)
    #[inline(always)]
    pub fn is_empty(&self) -> bool {
        self.sp == 0
    }

    /// Returns the estimated size this instance takes up in memory in bytes.
    #[inline(always)]
    pub fn size(&self) -> usize {
        self.buf.len() * mem::size_of::<Record>()
    }

    /// Returns an immutable reference to the record buffer.
    #[inline(always)]
    pub fn buffer(&self) -> &[Record] {
        &self.buf
    }

    /// Returns an immutable pointer to the record buffer data.
    #[inline(always)]
    pub fn as_ptr(&self) -> *const Record {
        self.buf.as_ptr()
    }

    /// Returns an mutable pointer to the record buffer data.
    #[inline(always)]
    pub fn as_mut_ptr(&mut self) -> *mut Record {
        self.buf.as_mut_ptr()
    }

    /// Returns the stack pointer index (sp).
    #[inline(always)]
    pub fn stack_ptr(&self) -> usize {
        self.sp
    }

    /// Pushes a new record into the stack.
    /// Remember that this never allocates, as the stack is fixed size.
    /// Does not check for stack overflow in release!
    #[inline(always)]
    pub fn push(&mut self, rec: Record) {
        debug_assert!(self.sp < self.buf.len(), "VM StackOverflow");
        self.sp += 1;
        self.buf[self.sp] = rec;
    }

    /// Pushes the stack to it's capacity.
    /// Warning! A push call after this will result in a stack overflow.
    #[inline(always)]
    pub fn push_all(&mut self) {
        self.sp = self.buf.len() - 1;
    }

    /// Pops the top stack record off the stack
    /// and decrements the stack pointer.
    #[inline(always)]
    pub fn pop(&mut self) {
        debug_assert_ne!(self.sp, 0, "VM_Stack_ZeroPop");
        debug_assert!(self.sp.checked_sub(1).is_some(), "VM_Stack_OverflowPop");
        self.sp -= 1;
    }

    /// Pops all records from the stack.
    /// The stack pointer is zero afterwards.
    #[inline(always)]
    pub fn pop_all(&mut self) {
        self.sp = 0
    }

    /// Pops multiple records from the stack.
    /// Count must be > 0!
    #[inline(always)]
    pub fn pop_multi(&mut self, count: usize) {
        debug_assert_ne!(count, 0, "VM_Stack_ZeroPop");
        debug_assert!(self.sp.checked_sub(count).is_some(), "VM_Stack_OverflowPop");
        self.sp -= count;
    }

    /// Pops the top stack record off the stack,
    /// decrements the stack pointer
    /// and returns the the former top element,
    #[inline(always)]
    pub fn pop_ret(&mut self) -> Record {
        debug_assert!(self.sp > 0, "VM_Stack_Underflow");
        let val = self.buf[self.sp];
        self.sp -= 1;
        val
    }

    /// Returns the record at the top of the stack.
    #[inline(always)]
    pub fn peek(&self) -> Record {
        debug_assert!(self.sp < self.buf.len(), "VM_Stack_OutOfRangePeek!");
        self.buf[self.sp]
    }

    /// Sets the element at the top of the stack.
    #[inline(always)]
    pub fn peek_set(&mut self, rec: Record) {
        debug_assert!(self.sp < self.buf.len(), "VM_Stack_OutOfRangePeek!");
        self.buf[self.sp] = rec
    }

    /// Returns the record at the offset from the stack pointer.
    /// Make sure 'idx' is less than the stack pointer
    /// and stack pointer minus 'idx' is less than the record buffer length.
    #[inline(always)]
    pub fn poke(&self, idx: usize) -> Record {
        debug_assert!(idx <= self.sp, "VM_Stack_OutOfRangePoke!");
        debug_assert!(self.sp - idx <= self.buf.len(), "VM_Stack_OutOfRangePoke!");
        self.buf[self.sp - idx]
    }

    /// Sets the record at the offset from the stack pointer.
    /// Make sure 'idx' is less than the stack pointer
    /// and stack pointer minus 'idx' is less than the record buffer length.
    #[inline(always)]
    pub fn poke_set(&mut self, idx: usize, rec: Record) {
        debug_assert!(idx <= self.sp, "VM_Stack_OutOfRangePoke!");
        debug_assert!(self.sp - idx <= self.buf.len(), "VM_Stack_OutOfRangePoke!");
        self.buf[self.sp - idx] = rec
    }

    /// Returns true if stack overflow happend.
    #[inline(always)]
    pub fn is_overflowed(&self) -> bool {
        self.sp >= self.buf.len()
    }

    /// Returns am immutable slice between the stack pointer and the offset.
    #[inline(always)]
    pub fn slice_at_duplet_offset2(&self, offset_a: usize, offset_b: usize) -> &[Record] {
        &self.buf[(self.sp - (offset_b - 1))..=self.sp - offset_a]
    }

    /// Returns a mutable slice between the stack pointer + offset_a and the stack pointer + offset_b
    #[inline(always)]
    pub fn slice_at_duplet_offset2_mut(
        &mut self,
        offset_a: usize,
        offset_b: usize,
    ) -> &mut [Record] {
        &mut self.buf[(self.sp - (offset_b - 1))..=self.sp - offset_a]
    }
}

impl<I> ops::Index<I> for Stack
where
    I: slice::SliceIndex<[Record]>,
{
    type Output = I::Output;

    #[inline(always)]
    fn index(&self, idx: I) -> &Self::Output {
        &self.buf[idx]
    }
}

impl<I> ops::IndexMut<I> for Stack
where
    I: slice::SliceIndex<[Record]>,
{
    #[inline(always)]
    fn index_mut(&mut self, idx: I) -> &mut Self::Output {
        &mut self.buf[idx]
    }
}

impl convert::From<Box<[Record]>> for Stack {
    /// Creates a new instance from a boxed array.
    /// Panics if length is zero!
    fn from(buf: Box<[Record]>) -> Self {
        assert_ne!(buf.len(), 0);
        Self { buf, sp: 0 }
    }
}

impl convert::From<Vec<Record>> for Stack {
    /// Creates a new instance from a vector.
    /// Panics if length is zero!
    fn from(buf: Vec<Record>) -> Self {
        assert_ne!(buf.len(), 0);
        Self {
            buf: buf.into_boxed_slice(),
            sp: 0,
        }
    }
}

impl fmt::Debug for Stack {
    /// Prints the stack with values.
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        writeln!(f, "\n+-----------------------------------------------+")?;
        writeln!(f, "|                     Stack                     |")?;
        writeln!(f, "+-----------------------------------------------+")?;
        for (i, rec) in self.buf.iter().enumerate() {
            writeln!(f, "| &{:#010X} | {:?}", i, rec)?
        }
        writeln!(f, "+----------------------End----------------------+\n")
    }
}

#[cfg(test)]
mod tests {
    use super::{mem, Record, Stack};

    #[test]
    fn allocator() {
        let stack = Stack::with_length(32);
        assert!(stack.is_empty());
        assert_eq!(stack.length(), 33); // Because first stack entry is unused.
        assert_eq!(stack.buffer().len(), 33);
        assert_eq!(stack.size(), stack.length() * mem::size_of::<Record>());
    }

    #[test]
    #[should_panic]
    fn mk_empty_from_vec() {
        let _ = Stack::from(Vec::new());
    }

    #[test]
    #[should_panic]
    fn mk_empty_from_arrc() {
        let _ = Stack::from(Vec::new().into_boxed_slice());
    }

    #[test]
    #[should_panic]
    fn poke_invalid() {
        let stack = Stack::with_length(32);
        let _ = stack.poke(2);
    }

    #[test]
    #[should_panic]
    fn poke_set_invalid() {
        let mut stack = Stack::with_length(32);
        stack.poke_set(1, Record::from(0i32));
    }

    #[test]
    #[should_panic]
    fn overflow() {
        let mut stack = Stack::with_length(32);
        stack.push_all();
        stack.push(Record::from(0));
        assert!(!stack.is_empty());
        assert!(stack.is_overflowed());
    }

    #[test]
    fn peek() {
        let mut stack = Stack::with_length(32);
        stack.push(Record::from(-10_i32));
        assert!(!stack.is_empty());
        assert!(!stack.is_overflowed());
        assert_eq!(stack.peek(), Record::from(-10_i32));
        stack.push(Record::from(1.999_f32));
        assert!(!stack.is_empty());
        assert!(!stack.is_overflowed());
        assert_eq!(stack.peek(), Record::from(1.999_f32));
    }

    #[test]
    fn peek_set() {
        let mut stack = Stack::with_length(32);
        stack.push(Record::from(-10_i32));
        assert!(!stack.is_empty());
        assert!(!stack.is_overflowed());
        assert_eq!(stack.peek(), Record::from(-10_i32));
        stack.peek_set(Record::from(1.999_f32));
        assert!(!stack.is_empty());
        assert!(!stack.is_overflowed());
        assert_eq!(stack.peek(), Record::from(1.999_f32));
    }

    #[test]
    fn poke() {
        let mut stack = Stack::with_length(32);
        stack.push(Record::from(-10_i32));
        stack.push(Record::from(10_i32));
        assert!(!stack.is_empty());
        assert!(!stack.is_overflowed());
        assert_eq!(stack.poke(1), Record::from(-10_i32));
        assert_eq!(stack.poke(0), Record::from(10_i32));
    }

    #[test]
    fn poke_set() {
        let mut stack = Stack::with_length(32);
        stack.push(Record::from(0i32));
        stack.push(Record::from(0i32));
        assert!(!stack.is_empty());
        assert!(!stack.is_overflowed());
        stack.poke_set(1, Record::from(-10_i32));
        stack.poke_set(0, Record::from(10_i32));
        assert_eq!(stack.poke(1), Record::from(-10_i32));
        assert_eq!(stack.poke(0), Record::from(10_i32));
        assert_eq!(stack.peek(), Record::from(10_i32));
    }

    #[test]
    fn push() {
        let mut stack = Stack::with_length(32);
        stack.push(Record::from(-10_i32));
        assert_eq!(stack.peek(), Record::from(-10_i32));
        assert!(!stack.is_empty());
        assert!(!stack.is_overflowed());
    }

    #[test]
    fn pop() {
        let mut stack = Stack::with_length(32);
        stack.push(Record::from(-10_i32));
        stack.pop();
        assert!(stack.is_empty());
        assert!(!stack.is_overflowed());
    }

    #[test]
    fn pop_multi() {
        let mut stack = Stack::with_length(32);
        stack.push(Record::from(10_i32));
        assert_eq!(stack.peek(), Record::from(10_i32));
        stack.pop_multi(1);
        assert!(stack.is_empty());
        assert!(!stack.is_overflowed());
    }

    #[test]
    #[should_panic]
    fn pop_multi_invalid() {
        let mut stack = Stack::with_length(32);
        stack.push(Record::from(10_i32));
        stack.pop_multi(2);
        assert!(stack.is_overflowed());
    }

    #[test]
    fn pop_all() {
        let mut stack = Stack::with_length(32);
        stack.push(Record::from(-10_i32));
        stack.pop_all();
        assert!(stack.is_empty());
        assert!(!stack.is_overflowed());
    }

    #[test]
    fn pop_ret() {
        let mut stack = Stack::with_length(32);
        stack.push(Record::from(10_i32));
        assert_eq!(stack.pop_ret(), Record::from(10_i32));
        assert!(stack.is_empty());
        assert!(!stack.is_overflowed());
    }
}
