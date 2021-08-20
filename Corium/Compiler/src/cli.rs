use chrono::Local;
use clap::{App, Arg, SubCommand};

const SOURCE_TEMPLATE: &str = r#"
    File: $FI
    Created: $MK
    Author: $AU
"#;

fn create_source_file(name: String) {
    let file_name = &name;
    let date = &Local::now().format("%Y-%m-%d][%H:%M:%S").to_string();
    let usr_name = &whoami::username();
    let mut content = SOURCE_TEMPLATE.to_string();
    content = content.replace("$FI", file_name);
    content = content.replace("$MK", date);
    content = content.replace("$AU", usr_name);
    std::fs::write(&name, content).unwrap_or_else(|_| {
        panic!("Failed to create source file: {:?}", name);
    });
}

pub fn process_args() {
    let _cli_args = App::new("CoriumCompiler")
        .version("0.1")
        .author("Mario Sieg \"pinsrq\" <mt3000@gmx.de>")
        .about("Compiler for the Corium programming language.")
        .get_matches();
}
