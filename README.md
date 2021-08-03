# SMOOTH STRATIFICATION

An algorithm to compute smooth stratifications of semialgebraic sets, based on the work of Gabrielov and Vorobjov. This
work is novel because, rather than using quantifier elimination like standard stratification algorithms, this method
computes partial derivatives of higher orders to find strata of progressively smaller dimension.

## Compile

```bash
make
```

## Usage

So far implemented for curves in R^2. First enter the polynomial f defining the curve. The algorithm will then output
the one and zero-dimensional strata of the curve.

