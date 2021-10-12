const SpellChecker = require('spellchecker');

const fs = require('fs');

function print(any) {
    console.log(any);
}

function getFiles(dir, files_) {
    files_ = files_ || [];
    var files = fs.readdirSync(dir);
    for (var i in files) {
        var name = dir + '/' + files[i];
        if (fs.statSync(name).isDirectory()) {
            getFiles(name, files_);
        } else {
            files_.push(name);
        }
    }
    return files_;
}
function getContent(filename) {
    var contents = fs.readFileSync(filename);
    return contents.toString();
}

function filterWrongWord(word) {
    return SpellChecker.isMisspelled(word)
}

function check(path) {
    const content = getContent(path);
    const lines = content.split('\n');
    for (i in lines) {
        const line = lines[i].split(' ');
        const wrongWords = line.filter(filterWrongWord);

        if (wrongWords.length == 0) { continue };
        print('\nfile: ' + path + ' line: ' + i)
        print(wrongWords)
    }
}

function contents() {
    const paths = getFiles('./repos')
    paths.forEach(path => check(path));
}

contents()


// console.log(SpellChecker.isMisspelled('isMisspelled'))