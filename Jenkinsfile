pipeline {
    agent {
        node {
            label "freebsd&&amd64"
        }
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
