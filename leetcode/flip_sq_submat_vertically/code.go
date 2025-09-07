package flipsqsubmatvertically

import "fmt"

func printGrid(grid [][]int) {
	n := len(grid)
	m := len(grid[0])
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Print(grid[i][j], " ")
		}
		fmt.Println()
	}
	fmt.Println()
}
func reverseSubmatrix(grid [][]int, x int, y int, k int) [][]int {
	for i := 0; i < k/2; i++ {
		for j := 0; j < k; j++ {
			grid[i+x][j+y], grid[x+k-i-1][j+y] = grid[x+k-i-1][j+y], grid[i+x][j+y]
		}
		// printGrid(grid)
	}

	return grid
}
