(async () => {
    let input = '';
    for await (const chunk of process.stdin) input += chunk;
    let lines = input.split(/\n/);
    const n = lines.shift();
    const points = lines.slice(0, n).map(line => line.split(/\s/).map(v => +v));

    let min = Infinity;
    let max = 0;
    for (const point of points) {
        min = Math.min(point[0] + point[1], min);
        max = Math.max(point[0] + point[1], max);
    }
    console.log(max - min);
})();
