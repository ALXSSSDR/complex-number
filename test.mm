#import <XCTest/XCTest.h>
#import "ComplexNumber.hpp"

@interface ComplexNumberTests : XCTestCase

@end

@implementation ComplexNumberTests

- (void)testAddition {
    
    ComplexNumber num1(2.0, 3.0);
    ComplexNumber num2(4.0, -2.0);

    ComplexNumber sum = num1 + num2;

    XCTAssertEqual(sum.getReal(), 6.0);
    XCTAssertEqual(sum.getImaginary(), 1.0);
}

- (void)testSubtraction {

    ComplexNumber num1(2.0, 3.0);
    ComplexNumber num2(4.0, -2.0);
    
    ComplexNumber diff = num1 - num2;
    
    XCTAssertEqual(diff.getReal(), -2.0);
    XCTAssertEqual(diff.getImaginary(), 5.0);
}

- (void)testMultiplication {

    ComplexNumber num1(2.0, 3.0);
    ComplexNumber num2(4.0, -2.0);
    
    ComplexNumber prod = num1 * num2;
    
    XCTAssertEqual(prod.getReal(), 14.0);
    XCTAssertEqual(prod.getImaginary(), 8.0);
}

- (void)testDivision {

    ComplexNumber num1(2.0, 3.0);
    ComplexNumber num2(4.0, -2.0);
    
    ComplexNumber quotient = num1 / num2;
    
    XCTAssertEqualWithAccuracy(quotient.getReal(), 0.2, 0.1);
    XCTAssertEqualWithAccuracy(quotient.getImaginary(), 1.4, 1);
}

- (void)testEquality {
    ComplexNumber num1(2.0, 3.0);
    ComplexNumber num2(4.0, -2.0);
    
    XCTAssertFalse(num1 == num2);
    XCTAssertTrue(num1 != num2);
}

- (void)testExponentiation {

    ComplexNumber num1(2.0, 3.0);
    
    ComplexNumber powResult = num1 ^ 3;
    
    XCTAssertEqual(powResult.getReal(), -46.0);
    XCTAssertEqual(powResult.getImaginary(), 9.0);
}

- (void)testMagnitude {

    ComplexNumber num1(2.0, 3.0);
    ComplexNumber num2(4.0, -2.0);
    
    XCTAssertEqualWithAccuracy(num1.getMagnitude(), 3.605, 0.001);
    XCTAssertEqualWithAccuracy(num2.getMagnitude(), 4.472, 0.001);
}

@end
