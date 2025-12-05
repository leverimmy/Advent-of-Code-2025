def main():
    with open('../assets/input.txt') as f:
        lines = f.read().splitlines()
    separator_index = lines.index('')
    range_lines = lines[:separator_index]
    ranges = []
    for line in range_lines:
        start, end = line.split('-')
        ranges.append((int(start), int(end)))
    ranges.sort(key=lambda x: (x[0], x[1]))
    current_l, current_r = None, None
    result = 0
    for l, r in ranges:
        if current_l is None or current_r is None:
            result += r - l + 1
            current_l, current_r = l, r
        elif l >= current_r + 1:
            current_l, current_r = l, r
            result += r - l + 1
        else:
            if r > current_r:
                result += r - current_r
                current_r = r
        
    print(result)

if __name__ == '__main__':
    main()

# Answer: 359913027576322
