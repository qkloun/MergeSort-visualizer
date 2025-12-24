# Welcome
This project is a part of multiple similar projects that visualize the process of how algorithms sort data, this one would be showing how MergeSort would organize a set of data. 
It was made with sdl2, a c++ library which let me open up a window and visualize the whole process on the screen.

This project let me understand how the MergeSort algorithm organizes data in a visual representation, which let me further understand the complexities of sorting systems. This project furthered my experience in coding as I hadn't done anything similar to this before, so I would like to believe that this project would let other students process sorting algorithms more.

## Features
- 🚀Real-time visualization of the merge sort algorithm<br>
- 📊Divide-and-conquer display showing recursive splitting and merging<br>
- 🌈Color-coded sections to highlight active subarrays<br>
- 🎬Smooth animations with step-by-step merge operations<br>
- 🎲Random data generation for varied demonstrations<br>
- 💫Interactive window with proper event handling<br>

## Algorithm Breakdown
The visualization demonstrates the three key phases of MergeSort:
1. **🔄 Divide Phase** - Array splits into smaller subarrays (highlighted in blue)
2. **⚡ Conquer Phase** - Individual elements are sorted (highlighted in green) 
3. **🔗 Merge Phase** - Sorted subarrays combine back together (highlighted in yellow)

### Visual Example
```
Unsorted: [38, 27, 43, 3, 9, 82, 10]
           ↓
Divide:   [38, 27, 43, 3] [9, 82, 10]
           ↓
Further:  [38, 27] [43, 3] [9, 82] [10]
           ↓
Merge:    [27, 38] [3, 43] [9, 82] [10]
           ↓
Sorted:   [3, 9, 10, 27, 38, 43, 82]
```

### Time Complexity
- Best Case: **O(n log n)**
- Average Case: **O(n log n)**
- Worst Case: **O(n log n)**

## Learning Outcomes
Building this visualizer helped me:
- Understand the recursive nature of divide-and-conquer algorithms
- Work with graphics programming using SDL2
- Translate abstract algorithms into visual representations
- Improve my C++ skills in a practical, engaging way

## Contributing
Contributions are welcome! Feel free to open issues or submit pull requests to improve the visualization or add new features.

## Watch the inspiration video!
<a href="https://www.youtube.com/watch?v=kPRA0W1kECg" target="_blank">
  <img src="https://img.youtube.com/vi/kPRA0W1kECg/maxresdefault.jpg" width="400"/></a>




&copy; 2025 GitHub &bull; [Code of Conduct](https://www.contributor-covenant.org/version/2/1/code_of_conduct/code_of_conduct.md)

