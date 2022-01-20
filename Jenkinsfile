pipeline {
    agent {
      label "freebsd&&amd64"
    }

    triggers {
        pollSCM '@hourly'
        cron '@daily'
    }

    options {
        ansiColor('xterm')
        buildDiscarder logRotator(artifactDaysToKeepStr: '', artifactNumToKeepStr: '', daysToKeepStr: '', numToKeepStr: '15')
        timestamps()
        disableConcurrentBuilds()
    }

    stages {
        stage("Configure") {
            steps {
                sh "mkdir -p build"
                dir('build') {
                    sh "cmake .. -DCMAKE_BUILD_TYPE=Release"
                }
            }
        }

        stage("Build") {
            steps {
                dir('build') {
                    sh "cmake --build . --verbose"
                }
            }
        }

        stage("Test") {
            steps {
                dir('build/tests') {
                    sh "ctest"
                }
            }
        }
    }
}
