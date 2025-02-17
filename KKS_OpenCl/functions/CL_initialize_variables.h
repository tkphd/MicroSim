void CL_initialize_variables() {

  int ip1, ip2, i1, i2, ip;

  pfmdat.nproc              = 1;
  pfmdat.jDimX              = MESH_Y;
  pfmdat.iDimY              = MESH_X;
  pfmdat.ntimesteps         = ntimesteps;
  pfmdat.savetime           = saveT;
  pfmdat.Tr                 = TLiquidus;
  pfmdat.sigma              = Gamma[0][1];
  pfmdat.Vm                 = V;
  pfmdat.D11s               = Diffusivity[0][0][0];
  pfmdat.D11l               = Diffusivity[1][0][0];
  pfmdat.interfaceDownlimit = 1e-4;
  pfmdat.interfaceUplimit   = 1.0 - pfmdat.interfaceDownlimit;

  pfmdat.phisolid           = 1.0;
  pfmdat.philiquid          = 0.0;
  pfmdat.Rg                 = R;
  // if (temperature > T) {
  //   pfmdat.T0                 = temperature;
  // }
  // else {
    pfmdat.T0                 = T;
  // }
  pfmdat.Teq                 = Teq;
  pfmdat.Tfill               = Tfill;
  pfmdat.ISOTHERMAL          = ISOTHERMAL;
  
  pfmdat.lrep               = 1.0;//(pfmdat.sigma*pfmdat.Vm)/(TLiquidus*R);//1.0;//CharLength*1e2;
  pfmdat.c1s_Initial        = cfill[0][0][0];
  pfmdat.c1l_Initial        = cfill[1][1][0];
  pfmdat.c1s_1stguess       = c_guess[0][0][0];
  pfmdat.c1l_1stguess       = c_guess[1][1][0];

  pfmdat.a2                 = 47.0/60.0;
  pfmdat.rad                = fill_cylinder_parameters.radius;
  pfmdat.epsc               = dab[0][1];
  pfmdat.intwidth           = epsilon;
  pfmdat.dxIntfcPoints      = 1;//NoOfPointsInInterface;//Not Used in NSM
  pfmdat.dtParam            = 1;//dtDenomParam; //Not Used in NSM
  pfmdat.InterfaceMobility  = -1.0;
  pfmdat.epsm               = 0.0;
  pfmdat.TLiquidus          = TLiquidus;
  pfmdat.Toffset            = temperature_gradientY.base_temp;
  //pfmdat.PosOffset          = PositionOffset;
  pfmdat.TPosOffset         = temperature_gradientY.gradient_OFFSET/deltay;
  //pfmdat.TG                 = TemperatureGradient;
  pfmdat.TGRADIENT          = temperature_gradientY.DeltaT/temperature_gradientY.Distance;
  //pfmdat.Vp                 = PullingVelocity;
  pfmdat.velocity           = temperature_gradientY.velocity;
  pfmdat.NoiseFac           = AMP_NOISE_PHASE;
  //pfmdat.angle              = RotAngles[0]*M_PI/180.0;
  pfmdat.shift_OFFSET       = shift_OFFSET; /* */
  
  for ( ip1 = 0; ip1 < 2; ip1++ ) { 
    for ( ip2 = 0; ip2 < 2; ip2++ ) { 
      for ( i1 = 0; i1 < 3; i1++ ) { 
        for ( i2 = 0; i2 < 3; i2++ ) { 
          pfmdat.Rotation_matrix[ip1][ip2][i1][i2] = Rotation_matrix[ip1][ip2][i1][i2]; 
          pfmdat.Inv_Rotation_matrix[ip1][ip2][i1][i2] = Inv_Rotation_matrix[ip1][ip2][i1][i2]; 
        }
      }
    }
  }
  
  
  for ( ip = 0; ip < NUMPHASES; ip++ ) { 
    pfmdat.thermophase[ip] = thermo_phase[ip];
    printf("ip = %d, thermo_phase[%d]\n", ip, ip);
  }

  pfmdat.RefD = 1.0;;

  pfmvar.E0                 = 1.0;//8.314*pfmdat.Tr/pfmdat.Vm;
  pfmvar.deltax             = deltax; 
  pfmvar.deltay             = deltay;
  pfmvar.deltat             = deltat; 
  pfmvar.Er                 = 8.314*pfmdat.Tr;
  //pfmvar.dx                 = pfmvar.deltax*pfmdat.lrep; // m
  //pfmvar.dy                 = pfmvar.deltay*pfmdat.lrep; // m
  //pfmvar.dt                 = pfmvar.deltat*pfmdat.lrep*pfmdat.lrep/(pfmdat.RefD);

  //printf("deltax = %le, deltat = %le \n", pfmvar.deltax, pfmvar.deltat);
  //printf("dx = %le, dt = %le \n", pfmvar.dx, pfmvar.dt);
    
  pfmvar.surfTen            = pfmdat.sigma; // /pfmdat.sigma; //pfmdat.sigma/(pfmdat.lrep*pfmvar.E0);//Nothing but 1
  pfmvar.ee                 = (6.0*pfmvar.surfTen*pfmdat.intwidth)/4.39445;
  pfmvar.w                  = (3.0*pfmvar.surfTen*4.39445)/pfmdat.intwidth;
  pfmvar.eesqrt             = sqrt(pfmvar.ee);
  pfmvar.IntMob             = pfmdat.InterfaceMobility*pfmdat.lrep*pfmvar.E0/pfmdat.RefD;

  //printf("surfTen = %le, ee = %le, w = %le \n", pfmvar.surfTen, pfmvar.ee, pfmvar.w);
  //printf("sigma = %le, intwidth = %le \n", pfmdat.sigma, pfmdat.intwidth);

  //printf("sigma=%le,lrep=%le,E0=%le,intwidth=%le,RefD=%le\n", pfmdat.sigma, pfmdat.lrep, pfmvar.E0, pfmdat.intwidth,pfmdat.RefD);

  if ( pfmdat.InterfaceMobility < 0.0 ) { 
    pfmvar.IntMobInv = 0.0;
  }
  else {
    pfmvar.IntMobInv = 1.0/pfmvar.IntMob;
  }

  NX = pfmdat.jDimX;
  NY = pfmdat.iDimY;

  NXNY = NX*NY;

  totny = NY + 2*pfmdat.nproc;
  totsliceny = (NY/pfmdat.nproc)+2;

  nx = NX+2;
  ny = totsliceny;

  pfmdat.jNx = nx;
  pfmdat.iNy = ny;

  nxtotny = nx*totny;
  nxny = nx*ny;

  globaldim0 = nx;
  globaldim1 = ny;

  globaldim[0] = globaldim0;
  globaldim[1] = globaldim1;

  gridNew  = (struct grid*)malloc(nxny*sizeof(struct grid));
  gridOld  = (struct grid*)malloc(nxny*sizeof(struct grid));
  cscl     = (struct csle*)malloc(nxny*sizeof(struct csle));
  temp     = (double*)malloc(nx*sizeof(double)); //Changed to nx, According to MESH_Y****
  tstep    = (long*)malloc(sizeof(long));
  propf4spline     = (struct propmatf4spline*)malloc(nx*sizeof(struct propmatf4spline));
  propf4spline1     = (struct propmatf4spline*)malloc(nx*sizeof(struct propmatf4spline));

  //pfmdat.myrank = rank;
  pfmdat.myrank = 0;
  istart = 0;
  iend = ny;

  t = STARTTIME;//1;
  tstart = STARTTIME;//1;
  tstep[0] = STARTTIME;//1;

  //deltax = pfmvar.deltax;
  //deltay = deltax;
  //deltaz = deltax;
  //deltat = pfmvar.deltat;

}
