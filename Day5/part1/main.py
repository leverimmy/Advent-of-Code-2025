def main():
    with open('../assets/input.txt') as f:
        lines = f.read().splitlines()
    separator_index = lines.index('')
    range_lines = lines[:separator_index]
    queries = lines[separator_index + 1:]
    ranges = []
    for line in range_lines:
        start, end = line.split('-')
        ranges.append((int(start), int(end)))
    results = []
    for query in queries:
        query = int(query)
        for l, r in ranges:
            if l <= query <= r:
                results.append('Yes')
                break
        else:
            results.append('No')
    print(sum(1 for result in results if result == 'Yes'))

if __name__ == '__main__':
    main()

# Answer: 840
