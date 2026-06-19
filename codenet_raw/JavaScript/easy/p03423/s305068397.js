module.exports = function (number) {
    if (number === 1 || number === 2 || number === 0) {
        return 0;
    }

    return Math.floor(number / 3);
}

process.stdout.write(module.exports(process.stdin));