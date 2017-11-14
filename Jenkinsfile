// trigger 10

def args = [
    ['debug', '--debug'],
    ['release', '--release-with-symbols'],
    ['optimized', '--O3']
]
def defaults = 'CFLAGS="-m64" LDFLAGS="-m64"'
def image = 'jhunkeler/buildsys'
def name = ''
def option = ''

for(int i = 0; i < args.size(); i++)
{
    name = args[i][0]
    option = args[i][1]

    node {
        //docker.image(image).inside {
            stage("Checkout") {
                checkout scm
            }
            def prefix = pwd() + '/_install'

            stage("System (${name})") {
                sh 'uname -a'
                sh 'lscpu'
                sh 'free -m'
                sh 'df -hT'
            }
            stage("Configure (${name})") {
                sh "yes '' | ./waf configure --prefix=${prefix} ${defaults} ${option}"
            }
            stage("Build (${name})") {
                sh './waf build'
            }
            stage("Install (${name})") {
                sh './waf install'
            }
            stage("Test (${name})") {
                sh "test -x ${prefix}/bin/calacs.e"
                stash name: "bin_${name}", includes: "_install/bin/*"
            }
        //}
    }
    //node {
    //    stage("Analyze (${name})") {
    //        dir("bin_${name}") {
    //            def info = sh(script: 'uname -s', returnStdout: true).trim()
    //            println("info='${info}'")
    //            unstash "bin_${name}"
    //            if (info == 'Linux') {
    //                sh 'find . -type f | xargs ldd'
    //            }
    //            else if (name == 'Darwin') {
    //                sh 'find . -type f | xargs otool -L'
    //            }
    //        }
    //    }
    //}
}
