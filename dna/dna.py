import csv
import sys

def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    with open(sys.argv[1]) as db:
        reader = csv.DictReader(db)
        people = list(reader)
        strs = reader.fieldnames[1:]  # All STR labels after "name"

    with open(sys.argv[2]) as file:
        sequence = file.read().strip()

    counts = {STR: longest_match(sequence, STR) for STR in strs}

    for person in people:
        if all(int(person[STR]) == counts[STR] for STR in strs):
            print(person["name"])
            return

    print("No match")

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0

        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run

if __name__ == "__main__":
    main()
