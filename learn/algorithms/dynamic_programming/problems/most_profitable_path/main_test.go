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
