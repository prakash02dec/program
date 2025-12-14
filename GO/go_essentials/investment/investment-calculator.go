package main

import (
	"fmt"
	"math"
)

const inflationRate = 2.5

func main() {
	
	var investAmount float64 = 1000
	var expectedReturnRate float64 = 5.5
	var year float64 = 10
	
	/*
	// another assignment method without var
	temp := 100
	fmt.Print(temp) 
	*/

	// print and scan 
	outputText("Enter the investment amount: ")
	fmt.Scan(&investAmount)

	// another way to print and scan
	fmt.Print("Enter the expected return rate: ")
	fmt.Scanf("%f", &expectedReturnRate)
	
	furtureValue , futureRealValue := calculateFutureValues(investAmount, expectedReturnRate, year)
	
	fmt.Println("Future Value : ",furtureValue)
	
	fmt.Printf(`Future Value : %0.2f
	After adjustment %0.2f`,furtureValue, futureRealValue)

	fmt.Println("Future value adjusted with inflation : ",futureRealValue)

	formatedfv := fmt.Sprintf("Future Value : %v",furtureValue)
	fmt.Println(formatedfv)

}

func outputText(text string) {
	fmt.Print(text)
}

func calculateFutureValues(investAmount, expectedReturnRate, year float64) (float64, float64) {
	furtureValue := float64(investAmount) * math.Pow(1+expectedReturnRate/100, year)
	futureRealValue := furtureValue/math.Pow(1+ inflationRate/100, year)
	return furtureValue, futureRealValue
}

/*
another way to return multiple values without declaring return values. 

func calculateFutureValues(investAmount, expectedReturnRate, year float64) (furtureValue float64, futureRealValue float64) {
	furtureValue = float64(investAmount) * math.Pow(1+expectedReturnRate/100, year)
	futureRealValue = furtureValue/math.Pow(1+ inflationRate/100, year)

	// return fv, frv
	return 
}

*/
