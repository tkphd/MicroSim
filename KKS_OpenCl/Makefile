FDIR=functions
SDIR=solverloop
CC=gcc
CFLAGS=-I.

IDIR =-I/usr/local/cuda/include/

LDIR =-L/usr/local/cuda/lib64/

_FUNCTION_DEPS = global_vars.h initialize_variables.h functions.h matrix.h utility_functions.h functionH.h functionF_01.h functionF_03.h  \
                 filling.h reading_input_parameters.h read_boundary_conditions.h  \
                 free_variables.h fill_domain.h CL_DeviceToHost.h Temperature_gradient.h shift.h CL_Shift.h CL_functionF_03_HostUpdate.h 
                 
DEPS = $(patsubst %,$(FDIR)/%,$(_FUNCTION_DEPS))

_SOLVERLOOP_DEPS = serialinfo_xy.h  file_writer.h initialize_functions_solverloop.h  

DEPS += $(patsubst %,$(SDIR)/%,$(_SOLVERLOOP_DEPS))

LIBS =-lm -lgsl -lgslcblas -lOpenCL

microsim_kks_opencl : microsim_kks_opencl.o 
	$(CC)  -o microsim_kks_opencl microsim_kks_opencl.o $(CFLAGS)  $(IDIR) $(LDIR) $(LIBS) 

microsim_kks_opencl.o : $(DEPS)       

.PHONY : clean

clean :

	rm -f microsim_kks_opencl.o microsim_kks_opencl *.out *.o  *.dat *.gz *.vtk *.txt *.mv *.log *.err *.epsc *.eps *.mat  *.png *.op *.jpg *.jpeg
