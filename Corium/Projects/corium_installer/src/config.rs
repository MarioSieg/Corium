use std::path::PathBuf;

pub struct Config {
    pub install_dir: PathBuf,
    pub add_to_path: bool,
    pub create_desktop_entry: bool,
}
