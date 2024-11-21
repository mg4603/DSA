package mostprofitablepath

import "testing"

func Test_max(t *testing.T) {
	type args struct {
		a int
		b int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "Case #1: (2,3)",
			args: args{a: 2, b: 3},
			want: 3,
		},
		{
			name: "Case #1: (6,5)",
			args: args{a: 6, b: 5},
			want: 6,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := max(tt.args.a, tt.args.b); got != tt.want {
				t.Errorf("max() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_MostProfit(t *testing.T) {
	tests := []struct {
		name string
		grid [][]int
		want int
	}{
		{
			name: "Base case #1: grid of size 1x1",
			grid: [][]int{{5}},
			want: 5,
		},
		{
			name: "Base case #2: grid of size 0x0",
			grid: [][]int{},
			want: 0,
		},
		{
			name: "Base case #3: grid of size 1x0",
			grid: [][]int{{}},
			want: 0,
		},
		{
			name: "Simple Case #1: grid of size 3x4",
			grid: [][]int{
				{0, 2, 2, 1},
				{3, 1, 1, 1},
				{4, 4, 2, 0},
			},
			want: 13,
		},
		{
			name: "Simple Case #2: grid of size 3x4",
			grid: [][]int{
				{0, 2, 2, 50},
				{3, 1, 1, 100},
				{4, 4, 2, 0},
			},
			want: 154,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := MostProfit(tt.grid); got != tt.want {
				t.Errorf("MostProfit(%v) = %v; want %v", tt.grid, got, tt.want)
			}
		})

	}
}
