pub trait Stage {
    const NAME: &'static str;

    fn new() -> Self;
    fn execute(&mut self) -> Result<(), String>;
}
