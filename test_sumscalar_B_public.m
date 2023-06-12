%% Test sumscalars_hw 1
mex sumscalars_hw_B_template.c
[sum, dim] = sumscalars_hw_B_template([3 6 4 2 -3 4]);
assert((sum==16) && (dim == 6));

%% Test sumscalars_hw 2
[sum, dim] = sumscalars_hw_B_template([12; 0; -3; 2]);
assert((sum==11) && (dim == 4));

%% Test sumscalars_hw 3
try 
    sum = sumscalars_hw_B_template(1,3);
catch ME
end
assert(strcmp(ME.identifier, 'Mex:nInputs'))