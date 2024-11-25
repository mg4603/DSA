package coinchange

import "testing"

func Test_coinChange(t *testing.T) {
	tests := []struct {
		name          string
		denominations []int
		n             int
		want          int
	}{

		{
			name:          "Basic case",
			denominations: []int{1, 2, 5},
			n:             5,
			want:          4, // {5}, {2,2,1}, {2,1,1,1}, {1,1,1,1,1}
		},
		{
			name:          "Single denomination",
			denominations: []int{1},
			n:             3,
			want:          1, // {1,1,1}
		},
		{
			name:          "No solution possible",
			denominations: []int{2, 4},
			n:             3,
			want:          0,
		},
		{
			name:          "Larger value",
			denominations: []int{1, 2, 5},
			n:             10,
			want:          10,
		},
		{
			name:          "Edge case zero",
			denominations: []int{1, 2, 5},
			n:             0,
			want:          1, // No coins needed
		},
		{
			name:          "Simple case",
			denominations: []int{1, 3, 5, 10},
			n:             3,
			want:          2,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := coinChange(tt.denominations, tt.n); got != tt.want {
				t.Errorf("coinChange(%v) = %v, want %v", tt.n, got, tt.want)
			}
		})
	}
}
