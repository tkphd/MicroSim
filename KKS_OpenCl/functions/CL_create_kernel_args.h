void CL_create_kernel_args() {
  
//   kernel1 = clCreateKernel(program, "SolverCsClEq", &ret);
//   if (ret!=CL_SUCCESS) {
//     printf("kernel1 SolverCsClEq error %d in rank = %d \n", ret, rank);
//     exit(1);
//   }
  kernel1_2 = clCreateKernel(program, "SolverCsClEq_2", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel1_2 SolverCsClEq_2 error %d in rank = %d \n", ret, rank);
    exit(1);
  }
  kernel1_3 = clCreateKernel(program, "SolverCsClEq_3", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel1_3 SolverCsClEq_3 error %d in rank = %d \n", ret, rank);
    exit(1);
  }
  kernel1_4 = clCreateKernel(program, "SolverCsClEq_4", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel1_4 SolverCsClEq_4 error %d in rank = %d \n", ret, rank);
    exit(1);
  }
//   kernel2a = clCreateKernel(program, "SolverPhiIso", &ret);
//   if (ret!=CL_SUCCESS) {
//     printf("kernel2a SolverPhiIso error %d\n", ret);
//   }
  kernel2a_2 = clCreateKernel(program, "SolverPhiIso_2", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel2a_2 SolverPhiIso_2 error %d\n", ret);
  }
  kernel2a_3 = clCreateKernel(program, "SolverPhiIso_3", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel2a_3 SolverPhiIso_3 error %d\n", ret);
  }
  kernel2a_4 = clCreateKernel(program, "SolverPhiIso_4", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel2a_4 SolverPhiIso_4 error %d\n", ret);
  }
//   kernel2b = clCreateKernel(program, "SolverPhi", &ret);
//   if (ret!=CL_SUCCESS) {
//     printf("kernel2b SolverPhi error %d\n", ret);
//   }
  kernel2b_2 = clCreateKernel(program, "SolverPhi_2", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel2b_2 SolverPhi_2 error %d\n", ret);
  }
  kernel2b_3 = clCreateKernel(program, "SolverPhi_3", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel2b_3 SolverPhi_3 error %d\n", ret);
  }
  kernel2b_4 = clCreateKernel(program, "SolverPhi_4", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel2b_4 SolverPhi_4 error %d\n", ret);
  }
//   kernel3a = clCreateKernel(program, "SolverCWoatr", &ret);
//   if (ret!=CL_SUCCESS) {
//     printf("kernel3a SolverCWoatr error %d\n", ret);
//   }
  kernel3a_2 = clCreateKernel(program, "SolverCWoatr_2", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel3a_2 SolverCWoatr_2 error %d\n", ret);
  }
  kernel3a_3 = clCreateKernel(program, "SolverCWoatr_3", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel3a_3 SolverCWoatr_3 error %d\n", ret);
  }
  kernel3a_4 = clCreateKernel(program, "SolverCWoatr_4", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel3a_4 SolverCWoatr_4 error %d\n", ret);
  }
//   kernel3b = clCreateKernel(program, "SolverCatr", &ret);
//   if (ret!=CL_SUCCESS) {
//     printf("kernel3b SolverCatr error %d\n", ret);
//   }
  kernel3b_2 = clCreateKernel(program, "SolverCatr_2", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel3b_2 SolverCatr_2 error %d\n", ret);
  }
  kernel3b_3 = clCreateKernel(program, "SolverCatr_3", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel3b_3 SolverCatr_3 error %d\n", ret);
  }
  kernel3b_4 = clCreateKernel(program, "SolverCatr_4", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel3b_4 SolverCatr_4 error %d\n", ret);
  }
  kernel5[0] = clCreateKernel(program, "apply_BC", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel5 apply_BC error %d\n", ret);
  }
  kernel5[1] = clCreateKernel(program, "apply_BC_jl_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel5 apply_BC_jl_noflux error %d\n", ret);
  }
  kernel5[2] = clCreateKernel(program, "apply_BC_jr_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel5 apply_BC_jr_noflux error %d\n", ret);
  }
  kernel5[3] = clCreateKernel(program, "apply_BC_jl_periodic", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel5 apply_BC_jl_periodic error %d\n", ret);
  }
  kernel5[4] = clCreateKernel(program, "apply_BC_jr_periodic", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel5 apply_BC_jr_periodic error %d\n", ret);
  }
  kernel5[5] = clCreateKernel(program, "apply_BC_it_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel5 apply_BC_it_noflux error %d\n", ret);
  }
  kernel5[6] = clCreateKernel(program, "apply_BC_ib_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel5 apply_BC_ib_noflux error %d\n", ret);
  }
  kernel5[7] = clCreateKernel(program, "apply_BC_it_periodic", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel5 apply_BC_it_period error %d\n", ret);
  }
  kernel5[8] = clCreateKernel(program, "apply_BC_ib_periodic", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel5 apply_BC_ib_period error %d\n", ret);
  }
  kernel6[0] = clCreateKernel(program, "apply_BC_phi", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel6 apply_BC_phi error %d\n", ret);
  }
  kernel6[1] = clCreateKernel(program, "apply_BC_phi_jl_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel6 apply_BC_phi_jl_noflux error %d\n", ret);
  }
  kernel6[2] = clCreateKernel(program, "apply_BC_phi_jr_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel6 apply_BC_phi_jr_noflux error %d\n", ret);
  }
  kernel6[3] = clCreateKernel(program, "apply_BC_phi_jl_periodic", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel6 apply_BC_phi_jl_periodic error %d\n", ret);
  }
  kernel6[4] = clCreateKernel(program, "apply_BC_phi_jr_periodic", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel6 apply_BC_phi_jr_periodic error %d\n", ret);
  }
  kernel6[5] = clCreateKernel(program, "apply_BC_phi_it_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel6 apply_BC_phi_it_noflux error %d\n", ret);
  }
  kernel6[6] = clCreateKernel(program, "apply_BC_phi_ib_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel6 apply_BC_phi_ib_noflux error %d\n", ret);
  }
  kernel6[7] = clCreateKernel(program, "apply_BC_phi_it_periodic", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel6 apply_BC_phi_it_periodic error %d\n", ret);
  }
  kernel6[8] = clCreateKernel(program, "apply_BC_phi_ib_periodic", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel6 apply_BC_phi_ib_periodic error %d\n", ret);
  }
  kernel7[0] = clCreateKernel(program, "apply_BC_com", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel7 apply_BC_com error %d\n", ret);
  }
  kernel7[1] = clCreateKernel(program, "apply_BC_com_jl_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel7 apply_BC_com_jl_noflux error %d\n", ret);
  }
  kernel7[2] = clCreateKernel(program, "apply_BC_com_jr_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel7 apply_BC_com_jr_noflux error %d\n", ret);
  }
  kernel7[3] = clCreateKernel(program, "apply_BC_com_jl_periodic", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel7 apply_BC_com_jl_periodic error %d\n", ret);
  }
  kernel7[4] = clCreateKernel(program, "apply_BC_com_jr_periodic", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel7 apply_BC_com_jr_periodic error %d\n", ret);
  }
  kernel7[5] = clCreateKernel(program, "apply_BC_com_it_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel7 apply_BC_com_it_noflux error %d\n", ret);
  }
  kernel7[6] = clCreateKernel(program, "apply_BC_com_ib_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel7 apply_BC_com_ib_noflux error %d\n", ret);
  }
  kernel7[7] = clCreateKernel(program, "apply_BC_com_it_periodic", &ret);
  if (ret!=CL_SUCCESS) {
      printf("kernel7 apply_BC_com_it_periodic error %d\n", ret);
  }
  kernel7[8] = clCreateKernel(program, "apply_BC_com_ib_periodic", &ret);
  if (ret!=CL_SUCCESS) {
      printf("kernel7 apply_BC_com_ib_periodic error %d\n", ret);
  }
  kernel8 = clCreateKernel(program, "addNoise", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel8 addNoise error %d\n", ret);
  }
  kernel9 = clCreateKernel(program, "copy_New_To_Old", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel9 copy_New_To_Old error %d\n", ret);
  }
  kernel10[0] = clCreateKernel(program, "update_temp_UC", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel10 update_temp_UC error %d\n", ret);
  }
  kernel10[1] = clCreateKernel(program, "update_temp_DS", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel10 update_temp_DS error %d\n", ret);
  }
  kernel10[2] = clCreateKernel(program, "update_temp_CR", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel10 update_temp_CR error %d\n", ret);
  }
  kernel11[0] = clCreateKernel(program, "apply_BC_temp_it_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel11 apply_BC_temp_it_noflux error %d\n", ret);
  }
  kernel11[1] = clCreateKernel(program, "apply_BC_temp_ib_noflux", &ret);
  if (ret!=CL_SUCCESS) {
    printf("kernel11 apply_BC_temp_ib_noflux error %d\n", ret);
  }

  
  /* Set OpenCL kernel arguments */
  // ret = clSetKernelArg(kernel1, 0, sizeof(cl_mem), &d_gridOld);
  // ret = clSetKernelArg(kernel1, 1, sizeof(cl_mem), &d_cscl);
  // ret = clSetKernelArg(kernel1, 2, sizeof(cl_mem), &d_pfmdat);
  // ret = clSetKernelArg(kernel1, 3, sizeof(cl_mem), &d_pfmvar);
  // ret = clSetKernelArg(kernel1, 4, sizeof(cl_mem), &d_temp);
  // ret = clSetKernelArg(kernel1, 5, sizeof(cl_mem), &d_tstep);
  // ret = clSetKernelArg(kernel1, 6, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel1_2, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel1_2, 1, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel1_2, 2, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel1_2, 3, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel1_2, 4, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel1_2, 5, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel1_2, 6, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel1_3, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel1_3, 1, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel1_3, 2, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel1_3, 3, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel1_3, 4, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel1_3, 5, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel1_3, 6, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel1_4, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel1_4, 1, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel1_4, 2, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel1_4, 3, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel1_4, 4, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel1_4, 5, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel1_4, 6, sizeof(cl_mem), &d_propf4);
  ret = clSetKernelArg(kernel1_4, 7, sizeof(cl_mem), &d_propf4spline);

  // ret = clSetKernelArg(kernel2a, 0, sizeof(cl_mem), &d_gridOld);
  // ret = clSetKernelArg(kernel2a, 1, sizeof(cl_mem), &d_gridNew);
  // ret = clSetKernelArg(kernel2a, 2, sizeof(cl_mem), &d_cscl);
  // ret = clSetKernelArg(kernel2a, 3, sizeof(cl_mem), &d_pfmdat);
  // ret = clSetKernelArg(kernel2a, 4, sizeof(cl_mem), &d_pfmvar);
  // ret = clSetKernelArg(kernel2a, 5, sizeof(cl_mem), &d_temp);
  // ret = clSetKernelArg(kernel2a, 6, sizeof(cl_mem), &d_tstep);
  // ret = clSetKernelArg(kernel2a, 7, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel2a_2, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel2a_2, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel2a_2, 2, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel2a_2, 3, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel2a_2, 4, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel2a_2, 5, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel2a_2, 6, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel2a_2, 7, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel2a_3, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel2a_3, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel2a_3, 2, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel2a_3, 3, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel2a_3, 4, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel2a_3, 5, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel2a_3, 6, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel2a_3, 7, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel2a_4, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel2a_4, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel2a_4, 2, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel2a_4, 3, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel2a_4, 4, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel2a_4, 5, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel2a_4, 6, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel2a_4, 7, sizeof(cl_mem), &d_propf4);
  ret = clSetKernelArg(kernel2a_4, 8, sizeof(cl_mem), &d_propf4spline);

  // ret = clSetKernelArg(kernel2b, 0, sizeof(cl_mem), &d_gridOld);
  // ret = clSetKernelArg(kernel2b, 1, sizeof(cl_mem), &d_gridNew);
  // ret = clSetKernelArg(kernel2b, 2, sizeof(cl_mem), &d_cscl);
  // ret = clSetKernelArg(kernel2b, 3, sizeof(cl_mem), &d_pfmdat);
  // ret = clSetKernelArg(kernel2b, 4, sizeof(cl_mem), &d_pfmvar);
  // ret = clSetKernelArg(kernel2b, 5, sizeof(cl_mem), &d_temp);
  // ret = clSetKernelArg(kernel2b, 6, sizeof(cl_mem), &d_tstep);
  // ret = clSetKernelArg(kernel2b, 7, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel2b_2, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel2b_2, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel2b_2, 2, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel2b_2, 3, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel2b_2, 4, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel2b_2, 5, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel2b_2, 6, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel2b_2, 7, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel2b_3, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel2b_3, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel2b_3, 2, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel2b_3, 3, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel2b_3, 4, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel2b_3, 5, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel2b_3, 6, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel2b_3, 7, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel2b_4, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel2b_4, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel2b_4, 2, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel2b_4, 3, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel2b_4, 4, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel2b_4, 5, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel2b_4, 6, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel2b_4, 7, sizeof(cl_mem), &d_propf4);
  ret = clSetKernelArg(kernel2b_4, 8, sizeof(cl_mem), &d_propf4spline);

  // ret = clSetKernelArg(kernel3a, 0, sizeof(cl_mem), &d_gridOld);
  // ret = clSetKernelArg(kernel3a, 1, sizeof(cl_mem), &d_gridNew);
  // ret = clSetKernelArg(kernel3a, 2, sizeof(cl_mem), &d_cscl);
  // ret = clSetKernelArg(kernel3a, 3, sizeof(cl_mem), &d_pfmdat);
  // ret = clSetKernelArg(kernel3a, 4, sizeof(cl_mem), &d_pfmvar);
  // ret = clSetKernelArg(kernel3a, 5, sizeof(cl_mem), &d_temp);
  // ret = clSetKernelArg(kernel3a, 6, sizeof(cl_mem), &d_tstep);
  // ret = clSetKernelArg(kernel3a, 7, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel3a_2, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel3a_2, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel3a_2, 2, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel3a_2, 3, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel3a_2, 4, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel3a_2, 5, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel3a_2, 6, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel3a_2, 7, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel3a_3, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel3a_3, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel3a_3, 2, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel3a_3, 3, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel3a_3, 4, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel3a_3, 5, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel3a_3, 6, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel3a_3, 7, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel3a_4, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel3a_4, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel3a_4, 2, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel3a_4, 3, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel3a_4, 4, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel3a_4, 5, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel3a_4, 6, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel3a_4, 7, sizeof(cl_mem), &d_propf4);
  ret = clSetKernelArg(kernel3a_4, 8, sizeof(cl_mem), &d_propf4spline);
  ret = clSetKernelArg(kernel3a_4, 9, sizeof(cl_mem), &d_propf4spline1);

  // ret = clSetKernelArg(kernel3b, 0, sizeof(cl_mem), &d_gridOld);
  // ret = clSetKernelArg(kernel3b, 1, sizeof(cl_mem), &d_gridNew);
  // ret = clSetKernelArg(kernel3b, 2, sizeof(cl_mem), &d_cscl);
  // ret = clSetKernelArg(kernel3b, 3, sizeof(cl_mem), &d_pfmdat);
  // ret = clSetKernelArg(kernel3b, 4, sizeof(cl_mem), &d_pfmvar);
  // ret = clSetKernelArg(kernel3b, 5, sizeof(cl_mem), &d_temp);
  // ret = clSetKernelArg(kernel3b, 6, sizeof(cl_mem), &d_tstep);
  // ret = clSetKernelArg(kernel3b, 7, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel3b_2, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel3b_2, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel3b_2, 2, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel3b_2, 3, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel3b_2, 4, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel3b_2, 5, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel3b_2, 6, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel3b_2, 7, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel3b_3, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel3b_3, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel3b_3, 2, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel3b_3, 3, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel3b_3, 4, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel3b_3, 5, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel3b_3, 6, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel3b_3, 7, sizeof(cl_mem), &d_propf3);

  ret = clSetKernelArg(kernel3b_4, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel3b_4, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel3b_4, 2, sizeof(cl_mem), &d_cscl);
  ret = clSetKernelArg(kernel3b_4, 3, sizeof(cl_mem), &d_pfmdat);
  ret = clSetKernelArg(kernel3b_4, 4, sizeof(cl_mem), &d_pfmvar);
  ret = clSetKernelArg(kernel3b_4, 5, sizeof(cl_mem), &d_temp);
  ret = clSetKernelArg(kernel3b_4, 6, sizeof(cl_mem), &d_tstep);
  ret = clSetKernelArg(kernel3b_4, 7, sizeof(cl_mem), &d_propf4);
  ret = clSetKernelArg(kernel3b_4, 8, sizeof(cl_mem), &d_propf4spline);
  ret = clSetKernelArg(kernel3b_4, 9, sizeof(cl_mem), &d_propf4spline1);

  for ( i = 0; i < 9; i++ ) {
    ret = clSetKernelArg(kernel5[i], 0, sizeof(cl_mem), &d_gridNew);
    ret = clSetKernelArg(kernel5[i], 1, sizeof(cl_mem), &d_pfmdat);

    ret = clSetKernelArg(kernel6[i], 0, sizeof(cl_mem), &d_gridNew);
    ret = clSetKernelArg(kernel6[i], 1, sizeof(cl_mem), &d_pfmdat);

    ret = clSetKernelArg(kernel7[i], 0, sizeof(cl_mem), &d_gridNew);
    ret = clSetKernelArg(kernel7[i], 1, sizeof(cl_mem), &d_pfmdat);
  }

  ret = clSetKernelArg(kernel8, 0, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel8, 1, sizeof(cl_mem), &d_pfmdat);

  ret = clSetKernelArg(kernel9, 0, sizeof(cl_mem), &d_gridOld);
  ret = clSetKernelArg(kernel9, 1, sizeof(cl_mem), &d_gridNew);
  ret = clSetKernelArg(kernel9, 2, sizeof(cl_mem), &d_pfmdat);

  for ( i = 0; i < 3; i++ ) { 
    ret = clSetKernelArg(kernel10[i], 0, sizeof(cl_mem), &d_temp);
    ret = clSetKernelArg(kernel10[i], 1, sizeof(cl_mem), &d_tstep);
    ret = clSetKernelArg(kernel10[i], 2, sizeof(cl_mem), &d_pfmdat);
    ret = clSetKernelArg(kernel10[i], 3, sizeof(cl_mem), &d_pfmvar);
  }

  for ( i = 0; i < 2; i++ ) {
    ret = clSetKernelArg(kernel11[i], 0, sizeof(cl_mem), &d_temp);
    ret = clSetKernelArg(kernel11[i], 1, sizeof(cl_mem), &d_tstep);
    ret = clSetKernelArg(kernel11[i], 2, sizeof(cl_mem), &d_pfmdat);
    ret = clSetKernelArg(kernel11[i], 3, sizeof(cl_mem), &d_pfmvar);
  }


}
