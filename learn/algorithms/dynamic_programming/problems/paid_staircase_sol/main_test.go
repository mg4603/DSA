package paidstaircasesol

import (
	"reflect"
	"testing"
)

func Test_reverseSlice(t *testing.T) {
	type args struct {
		s []int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{
			name: "Base case #1",
			args: args{
				s: []int{1, 2, 3, 4},
			},
			want: []int{4, 3, 2, 1},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := reverseSlice(tt.args.s); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("reverseSlice() = %v, want %v", got, tt.want)
			}
		})
	}
}
