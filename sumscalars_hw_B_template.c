#include <matrix.h>
#include <mex.h>

double compute_sum(double *cinput, int dim) {
    double sum = 0;
    for (int i = 0; i < dim; i++) {
        sum += cinput[i];
    }
    return sum;
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    // Check the number of input arguments
    if (nrhs != 1) {
        mexErrMsgIdAndTxt("Mex:nInputs", "Only one input argument is allowed.");
    }

    // Get the input parameter
    double *input = mxGetPr(prhs[0]);

    // Get the dimension of the input vector
    mwSize dim = mxGetNumberOfElements(prhs[0]);

    // Compute the sum
    double sum = compute_sum(input, dim);

    // Create the output arrays
    mxArray *outputSum = mxCreateDoubleScalar(sum);
    mxArray *outputDim = mxCreateDoubleScalar(dim);

    // Set the output arrays
    plhs[0] = outputSum;
    plhs[1] = outputDim;
}
