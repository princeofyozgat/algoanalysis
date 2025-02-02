# About the Project
I have compared the following sorting algorithms to see how they behave as the input size goes to large arrays.

# Algorithms
- BubbleSort
- Improved BubbleSort --> Checks to see if the array is sorted already. If so, terminates the process.
- SelectionSort
- QuickSort
- Improved QuickSort --> Uses SelectionSort instead of QuickSort if the Input size is small enough.
- MergeSort
- RadixSort

# Files

`project.c:` Contains the algorithm functions and related input sizes that will finish sorting around ~2 seconds for each of the algorithms. <br />
`arrayGenerator.c:` Generates an array filled with integer elements which take a value between 1 and 65536. (this is for RadixSort to work properly) <br />
`report.pdf:` Shows the time taken by each algorithm for various input sizes. <br />
