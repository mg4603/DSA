package fibonacci

import "testing"

func Test_fib(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want int
	}{
		{
			name: "Base case #1: n = 0",
			n:    0,
			want: 0,
		},
		{
			name: "Base Case #2: n = 1",
			n:    1,
			want: 1,
		},
		{
			name: "Base Case #3: n = 2",
			n:    2,
			want: 1,
		},
		{
			name: "Simple Case #1: n = 6",
			n:    6,
			want: 8,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := fib(tt.n); got != tt.want {
				t.Errorf("fib(%v) = %v, want %v", tt.n, got, tt.want)
			}
		})
	}
}
