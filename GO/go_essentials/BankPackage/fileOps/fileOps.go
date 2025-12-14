package fileOps

import (
	"fmt"
	"os"
	"strconv"
	"errors"
)


func ReadFloatFromFile(filename string) (float64, error) {
	// read the balance from a file
	data, err := os.ReadFile(filename)
	if err != nil {
		return 1000, errors.New("file not found")
	}

	dateText := string(data)
	var val float64
	val, err = strconv.ParseFloat(dateText, 64)
	if err != nil {
		return 1000 , errors.New("invalid data in file")
	}
	return val, nil
}

func WriteFloatToFile(value float64, filename string) {
	// write the balance to a file
	valueText := fmt.Sprint(value)
	os.WriteFile(filename, []byte(valueText), 0644)
}

/*
different package should be in subdirectory of the module
sub folder name should be same the package name
package name should be same as the folder name

*/