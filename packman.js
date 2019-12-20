'use strict';

const path = require('path');
const fs = require('fs');
const { execFile } = require('child_process');

function getCompilerPath() {
    return 'c:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Professional\\VC\\Tools\\MSVC\\14.16.27023\\bin\\Hostx64\\x64\\cl.exe';
}

console.clear();

const compilerPath = getCompilerPath();
const packagePath = path.join(__dirname, "package.json");
const packageContent = fs.readFileSync(packagePath);

const packageJson = JSON.parse(packageContent);
let args = [
    '/c',
    '/I',
    'c:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Professional\\VC\\Tools\\MSVC\\14.16.27023\\include\\'
];

packageJson.includes.forEach(item => {
    args.push('/I');
    args.push(path.join(__dirname, item));
});

packageJson.sources.forEach(item => {
    args.push(path.join(__dirname, item));
});

console.log(args);

const child = execFile(compilerPath, args, (err, stdout, stderr) => {
    if (err)
    {
        console.error(err);
    }

    console.log(stderr);
    console.log(stdout);
});
