package uniquepaths

import "testing"

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
