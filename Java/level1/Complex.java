class Complex {
    double re, im;

    double abs() {
        return Math.sqrt(re*re + im*im);
    }

    void add(Complex that) {
        Complex res = new Complex();
        re += that.re;
        im += that.im;
    }

    void sub(Complex that) {
        re -= that.re;
        im -= that.im;
    }

    void mul(Complex that) {
	double new_re = this.re*that.re - this.im*that.im;
	double new_im = this.re*that.im + this.im*that.re;
        re = new_re;
        im = new_im;
    }

    void conjugate() {
	im = -im;
    }

    void reciprocate() {
	double denominator = re*re + im*im;
	re /= denominator;
	im = -(im/denominator);
    }

    void div(Complex that) {
	    Complex c = new Complex();
	    c.re = that.re;
	    c.im = that.im;
	    c.reciprocate();
	    mul(c);
    }

}
