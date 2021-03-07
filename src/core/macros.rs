/// Implements a conditional branch jump with a logical type comparison between two operands.
#[macro_export]
macro_rules! impl_duplet_con_jmp {
    ($sta:ident, $cmd:ident, $op:tt, $tp:ty) => {
        let target_address: usize = $cmd.fetch().into();
        if <$tp>::from($sta.poke(1)) $op <$tp>::from($sta.peek()) {
            $cmd.jump(target_address);
        }
        $sta.pop_multi(2);
    }
}

/// Implements a conditional branch jump with a logical type comparison between two operands,
/// but one of them is specified.
#[macro_export]
macro_rules! impl_scalar_con_jmp {
    ($sta:ident, $cmd:ident, $op:tt, $val:expr, $tp:ty) => {
        let target_address: usize = $cmd.fetch().into();
        if <$tp>::from($sta.peek()) $op $val {
            $cmd.jump(target_address);
        }
        $sta.pop();
    }
}

/// Implements an arithmetic operation with two operands.
#[macro_export]
macro_rules! impl_duplet_op {
    ($sta:ident, $sc:ty, $op:tt) => {
        $sta.poke_set(
            1,
            Record::from(
                <$sc>::from($sta.poke(1)) $op
                <$sc>::from($sta.peek())
            )
        );
        $sta.pop();
    }
}

/// Implements an arithmetic operation with two operands,
/// but calls some static value on the type.
#[macro_export]
macro_rules! impl_duplet_op_static {
    ($sta:ident, $sc:ty, $proc:ident) => {
        $sta.poke_set(
            1,
            Record::from(<$sc>::from($sta.poke(1)).$proc(<$sc>::from($sta.peek()) as _)),
        );
        $sta.pop();
    };
}

/// Implements an arithmetic operation with two operands,
/// but one operand is already specified.
#[macro_export]
macro_rules! impl_scalar_op {
    ($sta:ident, $sc:ty, $op:tt, $v:expr) => {
        $sta.peek_set(
            Record::from(<$sc>::from($sta.peek())
            $op
            $v
        ));
    }
}

/// Implements an intrinsic procedure with one scalar parameter.
/// Pops the input argument and pushes the result.
#[macro_export]
macro_rules! impl_scalar_intrin {
    ($sta:ident, $sc:ty, $proc:ident) => {
        $sta.peek_set(Record::from(<$sc>::$proc(<$sc>::from($sta.peek()))));
    };
}

/// Implements an intrinsic procedure with two scalar parameters.
/// Pops the input arguments and pushes the result.
#[macro_export]
macro_rules! impl_duplet_intrin {
    ($sta:ident, $sc:ty, $proc:ident) => {
        $sta.poke_set(
            1,
            Record::from(<$sc>::$proc(
                <$sc>::from($sta.poke(1)),
                <$sc>::from($sta.peek()),
            )),
        );
        $sta.pop();
    };
}

#[macro_export]
macro_rules! impl_vector_op {
    ($sta:ident, $mod:ident, $proc:ident, $type:ty, $stride:expr) => {
        let x: &mut [$type] = {
            let z = $sta.slice_at_duplet_offset2_mut($stride, $stride * 2);
            unsafe { std::slice::from_raw_parts_mut(z.as_mut_ptr() as *mut _, z.len()) }
        };
        let y: &[$type] = {
            let z = $sta.slice_at_duplet_offset2(0, $stride);
            unsafe { std::slice::from_raw_parts(z.as_ptr() as *const _, z.len()) }
        };
        crate::simd::$mod::$proc(x, y);
        $sta.pop_multi($stride);
    };
}

#[macro_export]
macro_rules! impl_fma_vector_op {
    ($sta:ident, $mod:ident, $proc:ident, $type:ty, $stride:expr) => {
        let x: &mut [$type] = {
            let x = $sta.slice_at_duplet_offset2_mut($stride, $stride * 2);
            unsafe { std::slice::from_raw_parts_mut(x.as_mut_ptr() as *mut _, x.len()) }
        };
        let y: &[$type] = {
            let x = $sta.slice_at_duplet_offset2($stride, $stride * 2);
            unsafe { std::slice::from_raw_parts(x.as_ptr() as *const _, x.len()) }
        };
        let z: &[$type] = {
            let x = $sta.slice_at_duplet_offset2($stride, $stride * 3);
            unsafe { std::slice::from_raw_parts(x.as_ptr() as *const _, x.len()) }
        };
        crate::simd::$mod::$proc(x, y, z);
        $sta.pop_multi($stride);
    };
}
