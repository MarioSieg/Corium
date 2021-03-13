pipeline {
  agent any
  stages {
    stage('build') {
      steps {
          cmakeBuild(
            installation: 'InSearchPath'
          )
          sh 'cmake --build . --parallel 8'
          sh './Nominax'
      }
    }
  }
}
