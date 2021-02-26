use std::{fs, panic, time};

/// Install custom panic hook with crash dumps.
pub fn install_hooks(create_crash_dumps: bool) {
    let hook = move |info: &panic::PanicInfo| {
        let msg = info.payload().downcast_ref::<String>();
        let (file, row, col) = if let Some(x) = info.location() {
            (x.file(), x.line(), x.column())
        } else {
            ("UNKNOWN", 0, 0)
        };
        let chrono: u64 =
            if let Ok(x) = time::SystemTime::now().duration_since(time::SystemTime::UNIX_EPOCH) {
                x.as_secs()
            } else {
                0
            };
        let dump = format!(
            "[RoninVirtualMachine]\nCHRONO: {:X}\nFATAL INTERNAL ERROR: {}\n, FILE: {}, LINE: {}, COLUMN: {}\n",
            chrono,
            msg.unwrap_or(&String::from("UNKNOWN")),
            file, row, col
        );
        eprint!("{}", dump);
        if create_crash_dumps {
            let _ = fs::write(format!("{:X}.dmp", chrono), dump);
        }
    };

    panic::set_hook(Box::new(hook));
}

/// Uninstall custom panic hook.
pub fn uninstall_hook() {
    let _ = panic::take_hook();
}
