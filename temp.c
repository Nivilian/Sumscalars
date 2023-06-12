/*********************************************************************
 * sumscalars_hw_template.c
 *
 * This file shows the basics of setting up a mex file to work with
 * Matlab. It computes the sum of a vector
 *
 * Samuel Detzel, Mimed
 * Reviewed by Dingzhi Zhang, Mimed
 *
 * 3 points
 *
 * TODO Homework: Expand and modify the code from the lecture in such a way
 * that 
 * 
 * a) The dimension of the input vector is returned as a second output.
 * The signature of the resulting mex-file should look like this:
 * [sum, dim] = sumscalars_HW(input)
 * input:   1xn or nx1 vector 
 * sum:     sum of all elements in input
 * dim:     n, the length of the input vector
 *
 * b) The number of input arguments is checked at the beginning of the 
 * function. If the number of input arguments is NOT equal to 1 (one), the 
 * code should throw an error with the following signature:
 * "Mex:nInputs", "Too many or too few input arguments".
 *
 * Hints:   
 *  Start by having a look at how the first output (sum) is generated.
 *  Work your way backwards from there.
 *
 *  The length of the vector should be a second output after the first
 *  output (sum), not the second entry in a vector that contains both the 
 *  sum and the length. Otherwise, the tests will fail.
 *
 *  Have a look at how the function makes sure that only inputs of type 
 *  'double' are accepted, the number of elements can be checked in a 
 *  similar manner.
 *          
 *  Be careful not to break anything while modifiying the C Code.
 *  Frequently test if "mex sumscalars_hw_template" still runs. 
 *
 *  mexPrintf can be used to display variables to the console. It 
 *  uses C syntax for displaying numeric values.
 *
 *  If you are stuck, go back to the original template and try again
 *  rather than spending too much time fixing broken C code.
 *
 ********************************************************************/
 
 #include <matrix.h>			
 #include <mex.h> 				// https://de.mathworks.com/help/matlab/call-mex-files-1.html?s_tid=CRUX_lftnav


double compute_sum(double *cinput, int dim){
    double sum = 0;
    for(int i=0;i<dim;i++){
        sum += cinput[i];
    }
    return sum;
}


// gateway function, has to be included with this exact signature in every file to be converted to a mex-file
// takes the place of the usual main function
// lhs: left hand side, outputs
// rhs: right hand side, inputs
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])	// plhs and prhs are pointer to arrays
{ 
    
	// declare variables
	mxArray *input, *output;                         
    const mwSize *dimsinput;                                    
    double *cinput, *coutput;	
    double sum;                                                 
    int diminput_1, diminput_2;									
	  
	// associate inputs
	input = mxDuplicateArray(prhs[0]);                          // makes deep copy of input argument (all levels of data are copied)
    if (mxIsClass(input, "double")==0)
    {    
        mexErrMsgIdAndTxt("Mex:Datatype", "Expected input of type double!");
    }
    cinput = mxGetPr(input);									
    
	// figure out dimensions									
	dimsinput = mxGetDimensions(prhs[0]);						// returns array of format {4,5} for a 4x5 matrix 				
    diminput_1 = (int)dimsinput[0];
    diminput_2 = (int)dimsinput[1];                      
    
	if ((diminput_1!=1)&&(diminput_2!=1))
    {
        mexErrMsgIdAndTxt("Mex:MatrixDimensions", "Input has to be a 1xn or nx1 vector!");
    }
    
	// associate outputs
	output = mxCreateDoubleMatrix(1,1,mxREAL);			// returns pointer
	plhs[0] = output;
	
	// Associate pointer to the data in the mxArray
	coutput = mxGetPr(output);

    // call the function containing the algorithm
    if (diminput_2 > diminput_1){
        sum = compute_sum(cinput, diminput_2);
    }else{
        sum = compute_sum(cinput, diminput_1);
    }
    
    // associate output
    coutput[0]=sum;
     
}