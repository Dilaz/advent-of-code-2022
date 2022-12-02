const fs = require('fs/promises');

const INPUT_FILE = 'input.txt';

async function main() {
    const data = await fs.readFile(INPUT_FILE);

    const elves = data.toString('utf-8').split('\n\n');

    const largest = elves.map(elf => elf.split('\n').reduce((acc, weight) => acc + parseInt(weight, 10), 0)).sort((a,b) => b - a);
    console.log(largest);

    return largest.slice(0, 3).reduce((acc, w) => acc + w, 0);
}

main().then((res) => console.log(res));
