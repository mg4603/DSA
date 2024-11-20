package uniquepaths

import (
	"testing"
)

func Test_uniquePaths(t *testing.T) {
	type args struct {
		m int
		n int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "Base case #1",
			args: args{
				m: 1,
				n: 1,
			},
			want: 1,
		},
		{
			name: "Simple case #1",
			args: args{
				m: 2,
				n: 2,
			},
			want: 2,
		},
		{
			name: "Simple case #2",
			args: args{
				m: 1,
				n: 2,
			},
			want: 1,
		},
		{
			name: "Simple case #3",
			args: args{
				m: 2,
				n: 1,
			},
			want: 1,
		},
		{
			name: "Simple case #4",
			args: args{
				m: 2,
				n: 3,
			},
			want: 3,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := uniquePaths(tt.args.m, tt.args.n); got != tt.want {
				t.Errorf("uniquePaths() = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestHashset_Add(t *testing.T) {
	tests := []struct {
		name        string
		intputPairs []Pair
		checkPairs  []Pair
		expected    []bool
	}{
		{
			name: "Add Unique Pairs",
			intputPairs: []Pair{
				{i: 1, j: 2},
				{i: 3, j: 4},
			},
			checkPairs: []Pair{
				{i: 1, j: 2},
				{i: 3, j: 4},
				{i: 2, j: 3},
			},
			expected: []bool{true, true, false},
		},
		{
			name: "Add Duplicate Pairs",
			intputPairs: []Pair{
				{i: 1, j: 2},
				{i: 1, j: 2},
			},
			checkPairs: []Pair{
				{i: 1, j: 2},
			},
			expected: []bool{true},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			set := NewHashSet()

			for _, pair := range tt.intputPairs {
				set.Add(pair.i, pair.j)
			}

			for idx, pair := range tt.checkPairs {
				if got := set.Contains(pair.i, pair.j); got != tt.expected[idx] {
					t.Errorf("Contains (%v) : %v; want %v", pair, got, tt.expected[idx])
				}
			}
		})
	}

}
