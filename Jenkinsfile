pipeline {
  agent any
    stages {
      stage('install') {
        steps {
          sh """curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | bash -s -- -y"""
        }
      }
      stage('build') {
        steps {
          sh '$HOME/.cargo/bin/cargo build --release --all-features'
          sh '$HOME/.cargo/bin/cargo build --all-features'
        }
      }
      stage('test') {
        steps {
          sh '$HOME/.cargo/bin/cargo test'
          sh '$HOME/.cargo/bin/cargo clippy'
        }
      }
    }
}