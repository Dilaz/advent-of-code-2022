const fs = require('fs/promises');

const INPUT_FILE = 'input.txt';

async function main() {
    const data = await fs.readFile(INPUT_FILE);

    const elves = data.toString('utf-8').split('\n\n');

    return Math.max(...elves.map(elf => elf.split('\n').reduce((acc, weight) => acc + parseInt(weight, 10), 0)));
}

main().then((res) => console.log(res));
