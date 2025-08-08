#include <SDL2/SDL.h>
#include <iostream>
#include <random>
#include <vector>

// Function to draw the state of the array
void draw_state(std::vector<int>& v, SDL_Renderer* renderer, int left, int right, int mid) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    int index = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i >= left && i <= right) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Red for the current subarray
        } else if (i == mid) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue for the midpoint
        } else {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black for normal bars
        }

        SDL_RenderDrawLine(renderer, index, 0, index, 99 - v[i]);
        index += 1;
    }
    SDL_RenderPresent(renderer);
}

// Function to merge two halves of the array
void merge(std::vector<int>& v, int left, int mid, int right, SDL_Renderer* renderer, bool& running) {
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;     // Size of the right subarray

    // Create temporary arrays
    std::vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = v[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = v[mid + 1 + i];
    }

    // Merge the temporary arrays back into v[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;

        // Visualize the current state of the array
        draw_state(v, renderer, left, right, mid);
        SDL_Delay(50);

        // Handle SDL events to allow window closure
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
                return;
            }
        }
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;

        // Visualize the current state of the array
        draw_state(v, renderer, left, right, mid);
        SDL_Delay(50);

        // Handle SDL events to allow window closure
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
                return;
            }
        }
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;

        // Visualize the current state of the array
        draw_state(v, renderer, left, right, mid);
        SDL_Delay(50);

        // Handle SDL events to allow window closure
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
                return;
            }
        }
    }
}

// Function to perform merge sort
void merge_sort(std::vector<int>& v, int left, int right, SDL_Renderer* renderer, bool& running) {
    if (left >= right || !running) {
        return;  // Base case: if the subarray has one or no elements, it's already sorted
    }
    int mid = left + (right - left) / 2;  // Find the midpoint

    // Recursively sort the first and second halves
    merge_sort(v, left, mid, renderer, running);
    merge_sort(v, mid + 1, right, renderer, running);

    // Merge the sorted halves
    merge(v, left, mid, right, renderer, running);
}

int main() {
    std::random_device rd;
    std::uniform_int_distribution<> d(1, 99);

    std::vector<int> v;
    for (int i = 0; i < 100; i++) {
        v.push_back(d(rd));
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Merge Sort Visualization", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_RenderSetScale(renderer, 5, 5);

    bool running = true;
    merge_sort(v, 0, v.size() - 1, renderer, running);

    // Keep the window open after sorting is complete
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

