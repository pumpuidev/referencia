class Line {
	double a, b, c;

	boolean contains( Point p ){
		return a*p.x + b*p.y == c;
	}


	/* Ax+B=y   ax + by = c    (-a/b)x + c/b = y
	 * párhuzamos, ha a meredekség (A) megegyezik
	 * ha b==0, akkor függőleges
	*/
	boolean isParallelWith( Line that ){
		return (this.a * that.b == that.a * this.b);
	}

	boolean isOrthogonalTo( Line that ){
		return (this.a * that.a + this.b * that.b == 0);
	}
}
