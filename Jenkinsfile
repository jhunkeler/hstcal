def nodes = ['linux']
def release_modes = ['debug', 'optimized', 'release']
def release_args = ['--debug', '--O3', '--release-with-symbols']
def _test_args = "--basetemp=tests_output --junitxml results.xml --remote-data"

def CFLAGS = "CFLAGS=\"-m64\""
def LDFLAGS = "LDFLAGS=\"-m64\""
def DEFAULT_FLAGS = "${CFLAGS} ${LDFLAGS}"
def tasks = [:]
for(int i = 0; i < nodes.size(); i++)
{
    def node_is = nodes[i]

    for(int j = 0; j < release_modes.size(); j++)
    {
        def name = release_modes[j]
        def option = release_args[j]
        def test_args = _test_args

        // Run slow tests when in release mode
        if (name == 'release') {
            test_args += ' --slow'
        }

        tasks["${node_is}/${name}"] = {
            node {
                stage("Checkout") {
                    checkout scm
                }

                def prefix = pwd() + '/_install'
                def runtime = ["PATH=${prefix}/bin:${env.PATH}"]

                stage("Generate (${name})") {
                    sh "yes '' | ./waf configure --prefix=${prefix} ${option} ${DEFAULT_FLAGS}"
                    sh './waf build'
                    sh './waf install'
                }
                try {
                    stage("Test (${name})") {
                        sh 'conda install -q -y pytest astropy'
                        withEnv(runtime) {
                            sh "pytest ${test_args} tests"
                        }
                    }
                }
                catch (e) {
                    step([$class: 'XUnitBuilder',
                        thresholds: [
                        [$class: 'SkippedThreshold', failureThreshold: '0'],
                        [$class: 'FailedThreshold', unstableThreshold: '1'],
                        [$class: 'FailedThreshold', failureThreshold: '6']],
                        tools: [[$class: 'JUnitType', pattern: '*.xml']]])
                }
            }
        }
    }
}

stage("Matrix") {
    parallel tasks
}


