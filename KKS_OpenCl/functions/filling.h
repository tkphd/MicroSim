#ifndef FILLING_H_
#define FILLING_H_

#include "time.h"

int checkOverlap(long centx, long centy, long centz, double rad, long shield_dist, int *occupancy) {
  long x,y,z;
    if (!shield_dist)
        return 0;

    for (x = 0; x < rows_x; x++)
        for (y = 0; y < rows_y; y++)
            for (z = 0; z < rows_z; z++)
                if (occupancy[x*layer_size + z*rows_y + y] == 1)
                    if ((x - centx)*(x - centx) + (y - centy)*(y - centy)
                        + (z - centz)*(z - centz) <= (shield_dist*rad)*(shield_dist*rad))
                    return 1;
    return 0;
}

void fill_phase_cube (struct fill_cube fill_cube_parameters, struct fields* gridinfo, long b) {
  long x, y, z, index;
  long a;
  double sum;
  
  for(x=0;x < rows_x; x++) {
    for(z=0; z < rows_z; z++) {
      for (y=0; y < rows_y; y++) {
        index = x*layer_size + z*rows_y + y;
        
        if (b < (NUMPHASES-1)) {
          if ((x >= fill_cube_parameters.x_start) && (x <= fill_cube_parameters.x_end) && (y >=fill_cube_parameters.y_start) && (y<=fill_cube_parameters.y_end) && (z >=fill_cube_parameters.z_start) && (z<=fill_cube_parameters.z_end)) {
            
            gridinfo[index].phia[b] = 1.00000;
            for (a=0; a < NUMPHASES; a++) {
              if (b!=a) {
              gridinfo[index].phia[a] = 0.00000;
              }
            }
          } else {
            if (gridinfo[index].phia[b] != 1.0000) {
              gridinfo[index].phia[b] = 0.00000;
            }
          }
        } else {
          sum = 0.0;
          for (a=0; a < NUMPHASES-1; a++) {
            sum += gridinfo[index].phia[a];
          }
          if (sum > 1.0) {
            printf("Wrong filling operation, will fill it with liquid\n");
            gridinfo[index].phia[b] = 1.0;
            for (a=0; a < NUMPHASES-1; a++) {
              if (a!=b) {
                gridinfo[index].phia[a] = 0.00000;
              }
            }
          } else {
            gridinfo[index].phia[b]   = 1.0-sum;
          }
        }
      }
    }
  }
}

void fill_phase_ellipse (struct fill_ellipse fill_ellipse_parameters, struct fields* gridinfo, long b) {
  long x, y, z, gidy;
  long a;
  double x_;
  double y_;
  double sum;
  long x_center, y_center, z_center;
  double l, e, angle;
  double angle_rad = angle*M_PI/180.0;
  
  x_center =  fill_ellipse_parameters.x_center;
  y_center =  fill_ellipse_parameters.y_center;
  z_center =  fill_ellipse_parameters.z_center;
  l        =  fill_ellipse_parameters.major_axis;
  e        =  fill_ellipse_parameters.eccentricity;
  angle    =  fill_ellipse_parameters.rot_angle;
  
  for(x=0;x<=(MESH_X-1);x++) {
    for (y=0; y<=(MESH_Y-1); y++) {
      if (b < (NUMPHASES-1)) {
        if ((double)(x-x_center)*(x-x_center)/(l*l) + ((double)(y-y_center)*(y-y_center))/(e*e*l*l) <= 1.0) {
          x_ =  x_center + floor((double)(x-x_center)*cos(angle_rad)  + (double)(y-y_center)*sin(angle_rad));
          y_ =  y_center + floor(-(double)(x-x_center)*sin(angle_rad) + (double)(y-y_center)*cos(angle_rad));
        } else {
          x_ = x;
          y_ = y;
        }
        gidy = x_*MESH_Y + y_;
        if ((gidy < (MESH_X*MESH_Y)) && (gidy > 0)) {
          if ((double)(x-x_center)*(x-x_center)/(l*l) + ((double)(y-y_center)*(y-y_center))/(e*e*l*l) <= 1.0) {
            gridinfo[gidy].phia[b] = 1.00000;
            for (a=0; a < NUMPHASES; a++) {
              if (b!=a) {
              gridinfo[gidy].phia[a] = 0.00000;
              }
            }
          } else {
            if (gridinfo[gidy].phia[b] != 1.0000) {
              gridinfo[gidy].phia[b] = 0.00000;
            }
          }
        }
      } else {
        gidy = x*MESH_Y + y;
        sum = 0.0;
        for (a=0; a < NUMPHASES-1; a++) {
          sum += gridinfo[gidy].phia[a];
        }
        if (sum > 1.0) {
          printf("Wrong filling operation, will fill it with liquid\n");
          gridinfo[gidy].phia[b] = 1.0;
          for (a=0; a < NUMPHASES-1; a++) {
            if (a!=b) {
             gridinfo[gidy].phia[a] = 0.00000;
            }
          }
        } else {
          gridinfo[gidy].phia[b]   = 1.0-sum;
        }
      }
    }
  }
}
void fill_phase_cylinder(struct fill_cylinder fill_cylinder_parameters, struct fields* gridinfo, long b) {
  long x, y, z, index;
  long a;
  double sum;
  
  long x_center, y_center, z_start, z_end;
  double radius;
  
  x_center = fill_cylinder_parameters.x_center;
  y_center = fill_cylinder_parameters.y_center;
  z_start  = fill_cylinder_parameters.z_start;
  z_end    = fill_cylinder_parameters.z_end;
  radius   = fill_cylinder_parameters.radius;
  
  for(x=0;x < rows_x; x++) {
    for (z=0; z < rows_z; z++) {
      for (y=0; y < rows_y; y++) {
        index = x*layer_size + z*rows_y + y;
        if (b < (NUMPHASES-1)) {
          if (((x-x_center)*(x-x_center) + (y-y_center)*(y-y_center) <= radius*radius) && (z>=z_start) && (z<=z_end)) {
            gridinfo[index].phia[b] = 1.00000;
            for (a=0; a < NUMPHASES; a++) {
              if (b!=a) {
              gridinfo[index].phia[a] = 0.00000;
              }
            }
          } else {
            if (gridinfo[index].phia[b] != 1.0000) {
              gridinfo[index].phia[b] = 0.00000;
            }
          }
        } else {
          sum = 0.0;
          for (a=0; a < NUMPHASES-1; a++) {
            sum += gridinfo[index].phia[a];
          }
          if (sum > 1.0) {
            printf("Wrong filling operation, will fill it with liquid\n");
            gridinfo[index].phia[b] = 1.0;
            for (a=0; a < NUMPHASES-1; a++) {
              if (a!=b) {
              gridinfo[index].phia[a] = 0.00000;
              }
            }
          } else {
            gridinfo[index].phia[b]   = 1.0-sum;
          }
        }
      }
    }
  }
}
void fill_phase_sphere(struct fill_sphere fill_sphere_parameters, struct fields* gridinfo, long b) {
  long x, y, z, index;
  long a;
  double sum;
  
  long x_center, y_center, z_center;
  double radius;
  
  x_center = fill_sphere_parameters.x_center;
  y_center = fill_sphere_parameters.y_center;
  z_center = fill_sphere_parameters.z_center;
  radius   = fill_sphere_parameters.radius;
  
  for(x=0;x < rows_x; x++) {
    for (z=0; z < rows_z; z++) {
      for (y=0; y < rows_y; y++) {
        index = x*layer_size + z*rows_y + y;
        if (b < (NUMPHASES-1)) {
          if (((x-x_center)*(x-x_center) + (y-y_center)*(y-y_center) + (z- z_center)*(z-z_center) <= radius*radius)) {
            gridinfo[index].phia[b] = 1.00000;
            for (a=0; a < NUMPHASES; a++) {
              if (b!=a) {
              gridinfo[index].phia[a] = 0.00000;
              }
            }
          } else {
            if (gridinfo[index].phia[b] != 1.0000) {
              gridinfo[index].phia[b] = 0.00000;
            }
          }
        } else {
          sum = 0.0;
          for (a=0; a < NUMPHASES-1; a++) {
            sum += gridinfo[index].phia[a];
          }
          if (sum > 1.0) {
            printf("Wrong filling operation, will fill it with liquid\n");
            gridinfo[index].phia[b] = 1.0;
            for (a=0; a < NUMPHASES-1; a++) {
              if (a!=b) {
              gridinfo[index].phia[a] = 0.00000;
              }
            }
          } else {
            gridinfo[index].phia[b]   = 1.0-sum;
          }
        }
      }
    }
  }
}
void fill_phase_sphere_occupancy(struct fill_sphere fill_sphere_parameters, struct fields* gridinfo, long b, int* occupancy) {
  long x, y, z, index;
  long a;
  double sum;
  
  long x_center, y_center, z_center;
  double radius;
  
  x_center = fill_sphere_parameters.x_center;
  y_center = fill_sphere_parameters.y_center;
  z_center = fill_sphere_parameters.z_center;
  radius   = fill_sphere_parameters.radius;
  
  for(x=0;x < rows_x; x++) {
    for (z=0; z < rows_z; z++) {
      for (y=0; y < rows_y; y++) {
        index = x*layer_size + z*rows_y + y;
        if (b < (NUMPHASES-1)) {
          if (((x-x_center)*(x-x_center) + (y-y_center)*(y-y_center) + (z- z_center)*(z-z_center) <= radius*radius)) {
            gridinfo[index].phia[b] = 1.00000;
             occupancy[index] = 1;
            for (a=0; a < NUMPHASES; a++) {
              if (b!=a) {
              gridinfo[index].phia[a] = 0.00000;
              }
            }
          } else {
            if (gridinfo[index].phia[b] != 1.0000) {
              gridinfo[index].phia[b] = 0.00000;
            }
          }
        } else {
          sum = 0.0;
          for (a=0; a < NUMPHASES-1; a++) {
            sum += gridinfo[index].phia[a];
          }
          if (sum > 1.0) {
            printf("Wrong filling operation, will fill it with liquid\n");
            gridinfo[index].phia[b] = 1.0;
            for (a=0; a < NUMPHASES-1; a++) {
              if (a!=b) {
              gridinfo[index].phia[a] = 0.00000;
              }
            }
          } else {
            gridinfo[index].phia[b]   = 1.0-sum;
          }
        }
      }
    }
  }
}

void fill_phase_sphere_random(long phase, double ppt_radius, double volume_fraction, long shield_dist, double spread) {
  int overlap = 1;
  int *occupancy;
  long i;
  occupancy = (int*)malloc(sizeof(int)*rows_x*rows_y*rows_z);

  for (i = 0; i < rows_x*rows_y*rows_z; i++) {
    occupancy[i] = 0;
  }
  clock_t SEED = clock();
  double volume_domain = (double) MESH_X*MESH_Y*MESH_Z;
  double volume_per_particle = (double)(ppt_radius*ppt_radius*ppt_radius)*(4.0/3.0)*M_PI;

  int num_particles = ceil(volume_domain*volume_fraction/volume_per_particle);
  printf("Domain volume = %le, ppt_radius = %le, volume_per_particle = %le, Number of particles = %d\n", volume_domain, ppt_radius, volume_per_particle, num_particles);

  long particle_index = 1, random_count = 0, random_limit = 1e+5;

  struct fill_sphere temp_sph;

  while (particle_index <= num_particles) {
    
      long centx = MESH_X*drand48();
      long centy = MESH_Y*drand48();
      long centz = MESH_Z*drand48();

      temp_sph.x_center = centx;
      temp_sph.y_center = centy;
      temp_sph.z_center = centz;

      double mdev = spread*ppt_radius;
      double rad  = (double)ppt_radius + (1.0*drand48() - 0.5)*mdev;

      temp_sph.radius = rad;
      //printf("particle_index = %d, x_center = %ld, y_center = %ld, z_start = %ld, z_end = %ld, radius = %lf\n", particle_index, centx, centy, temp_cyl.z_start, temp_cyl.z_end, rad);

      random_count++;
      if (random_count > random_limit) {
        printf("Random filling attempt count limit = %ld reached. Only %ld particles could be filled.\n", random_limit, particle_index-1);
        break;
      }

      if (((centx - rad) < 0.0) || ((centx + rad) > (MESH_X-1)) ||
          ((centy - rad) < 0.0) || ((centy + rad) > (MESH_Y-1)) ||
          ((centz - rad) < 0.0) || ((centz + rad) > (MESH_Z-1)) )
          continue;

      overlap = checkOverlap(centx, centy, centz, rad, shield_dist, occupancy);

      if(overlap == 0) {
        fill_phase_sphere_occupancy(temp_sph, gridinfo, phase, occupancy);
        //fill_phase_cylinder(temp_cyl, gridinfo, b);
      }
      else {
        overlap = 1;
        continue;
      }
      particle_index++;
  }
  fill_phase_sphere_occupancy(temp_sph, gridinfo, NUMPHASES-1, occupancy);
  free(occupancy);
}

void fill_phase_cylinder_occupancy(struct fill_cylinder fill_cylinder_parameters, struct fields* gridinfo, long b, int* occupancy) {
    long x, y, z, index;
    long a;
    double sum;

    long x_center, y_center, z_start, z_end;
    double radius;

    x_center = fill_cylinder_parameters.x_center;
    y_center = fill_cylinder_parameters.y_center;
    z_start  = fill_cylinder_parameters.z_start;
    z_end    = fill_cylinder_parameters.z_end;
    radius   = fill_cylinder_parameters.radius;

    for(x = 0; x < rows_x; x++) {
      for (y = 0; y < rows_y; y++) {
        for (z = 0; z < rows_z; z++) {
            index = x*layer_size + z*rows_y + y;
            if ((z >= z_start) && (z <= z_end)) {
              if (b < (NUMPHASES-1)) {
                if (((x-x_center)*(x-x_center) + (y-y_center)*(y-y_center) <= radius*radius)) {
                  gridinfo[index].phia[b] = 1.00000;
                  occupancy[index] = 1;
                  for (a = 0; a < NUMPHASES; a++) {
                    if (b != a) {
                        gridinfo[index].phia[a] = 0.00000;
                    }
                  }
                } else if (gridinfo[index].phia[b] != 1.0000) {
                    gridinfo[index].phia[b] = 0.00000;
                }
            } else {
              sum = 0.0;
              for (a=0; a < NUMPHASES-1; a++) {
                sum += gridinfo[index].phia[a];
              }
              if (sum > 1.0) {
                printf("Wrong filling operation, will fill it with liquid\n");
                gridinfo[index].phia[b] = 1.0;
                for (a=0; a < NUMPHASES-1; a++) {
                  if (a!=b) {
                    gridinfo[index].phia[a] = 0.00000;
                  }
                }
              } else {
                gridinfo[index].phia[b]   = 1.0-sum;
              }
           }
        }
      }
    }
  }
}
void fill_phase_cylinder_random(long phase, double ppt_radius, double volume_fraction, long shield_dist, double spread) {
    int overlap = 1;
    int *occupancy;
    long i;
    occupancy = (int*)malloc(sizeof(int)*rows_x*rows_y*rows_z);

    for (i = 0; i < rows_x*rows_y*rows_z; i++) {
        occupancy[i] = 0;
    }

    clock_t SEED = clock();
    double volume_domain = (double) MESH_X*MESH_Y*MESH_Z;
    double volume_per_particle = (double)(ppt_radius*ppt_radius)*M_PI;

    int num_particles = ceil(volume_domain*volume_fraction/volume_per_particle);
    printf("Domain volume = %le, ppt_radius = %le, volume_per_particle = %le, Number of particles = %d\n", volume_domain, ppt_radius, volume_per_particle, num_particles);

    long particle_index = 1, random_count = 0, random_limit = 1e+4;

    struct fill_cylinder temp_cyl;
    temp_cyl.z_start  = 0;
    temp_cyl.z_end    = 0;

    while (particle_index <= num_particles)
    {
        long centx = MESH_X*drand48();
        long centy = MESH_Y*drand48();
        long centz = 0;

        temp_cyl.x_center = centx;
        temp_cyl.y_center = centy;

        double mdev = spread*ppt_radius;
        double rad  = (double)ppt_radius + (1.0*drand48() - 0.5)*mdev;

        temp_cyl.radius = rad;
//         printf("particle_index = %d, x_center = %ld, y_center = %ld, z_start = %ld, z_end = %ld, radius = %lf\n", particle_index, centx, centy, temp_cyl.z_start, temp_cyl.z_end, rad);

        random_count++;
        if (random_count > random_limit)
        {
            printf("Random filling attempt count limit = %ld reached. Only %ld particles could be filled.\n", random_limit, particle_index-1);
            break;
        }

        if (((centx - rad) < 0.0) || ((centx + rad) > (MESH_X-1)) ||
            ((centy - rad) < 0.0) || ((centy + rad) > (MESH_Y-1)) )
            continue;

        overlap = checkOverlap(centx, centy, centz, rad, shield_dist, occupancy);

        if(overlap == 0)
        {
            fill_phase_cylinder_occupancy(temp_cyl, gridinfo, phase, occupancy);
//             fill_phase_cylinder_occupancy(temp_cyl, gridinfo, 0, occupancy);
//             fill_phase_cylinder(temp_cyl, gridinfo, b);
        }
        else
        {
            overlap = 1;
            continue;
        }

        particle_index++;
    }
    fill_phase_cylinder_occupancy(temp_cyl, gridinfo, NUMPHASES-1, occupancy);
    free(occupancy);
}


void fill_composition_cube(struct fields* gridinfo) {
  long x, y, z, index;
  long k;
  long b;
  double c[NUMCOMPONENTS-1];
  double chemical_potential;
  long PHASE_FILLED=0;
  
  for(x=0;x<rows_x;x++) {
    for(z=0; z<rows_z; z++) {
      for (y=0; y<rows_y; y++) {
        index = x*layer_size + z*rows_y + y;
        PHASE_FILLED = 0;
        for (b=0; b < NUMPHASES-1; b++) {
          if (gridinfo[index].phia[b] == 1.0) {
            for (k=0; k < NUMCOMPONENTS-1; k++) {
              c[k] = ceq[b][b][k];
            }
            //init_propertymatrices(Teq);
            // chemical_potential = 2.0*ceq[NUMPHASES-1][NUMPHASES-1][0];
            Mu(c, Teq, b, gridinfo[index].compi);
            for (k=0; k < NUMCOMPONENTS-1; k++) {
              //chemical_potential = Mu(c, Teq, b, k);
              gridinfo[index].composition[k] = c[k];//chemical_potential;
              // printf("solid_chemical_potential=%le\n",gridinfo[gidy].compi[k]);
            }
            PHASE_FILLED =1;
            break;
          }
        }
        if (!PHASE_FILLED) {
          //Fill with liquid
          for (k=0; k < NUMCOMPONENTS-1; k++) {
            c[k] = cfill[NUMPHASES-1][NUMPHASES-1][k];
          }
  //         c[0] = 0.160413;
  //         c[1] = 0.245857;
//           init_propertymatrices(Teq);
          Mu(c, Teq, NUMPHASES-1, gridinfo[index].compi); 
          for (k=0; k < NUMCOMPONENTS-1; k++) {
            //chemical_potential = Mu(c, Teq, NUMPHASES-1, k);
//             printf("chemical_potential =%le\n", chemical_potential);
            gridinfo[index].composition[k] = c[k];
          }
        }
        //printf("%ld, %ld, %ld, %le\n", x, y, z, gridinfo[index].composition[0]);
      }
    }
  }
//   exit(0);
  //init_propertymatrices(T);
}

#endif





// void initdomain_struct(struct variables *gridinfo) {
//   long x,y;
//   double chemical_potential;
//   FILE *fp;
//   long b, k;
//   
//   char name[1000];
//   
//   //Filling algorithm for the phases---------------------------------------------------------------
//   long cubes;
//   long start_cube;
//   
//   char pattern[10000];
//   sprintf(pattern, "01");
//   long pattern_length = 2;
//   long period = (MESH_X-1);
//   long numperiods=1;
//   //Filling cubes of phases
//   //Filling abg configuration for half the domain--------------------------------------------------
//   start_cube = 0;  
//   //Determine the number of cubes of each phase in the pattern
//   find_numcubes(pattern, filling_type_phase);
//   long lambda = period/numperiods;
// 
//   for (a=0; a < NUMPHASES; a++) {
//     filling_type_phase[a].length = ((filling_type_phase[a].volume_fraction/filling_type_phase[a].NUMCUBES)*lambda);
//   }
//   
// //   fillpattern(pattern, filling_type_phase, start_cube, numperiods, gridinfo);
// 
// //You need to write your filling function here
// //   fill_random();
//   fill_cube_parameters.x_start = 0;
//   fill_cube_parameters.x_end   = MESH_X-1;
//   fill_cube_parameters.y_start = 0;
//   fill_cube_parameters.y_end   = 20;
//  fill_phase_cube(fill_cube_parameters, gridinfo, 0);
//  fill_phase_cube(fill_cube_parameters, gridinfo, NUMPHASES-1);
//   
//   
// //   fill_phase_circle(10, 0,               0, gridinfo, 0);
// //   fill_phase_circle(10, 0.25*(MESH_X-1), 0, gridinfo, 0);
// //   fill_phase_circle(10, 0.5*(MESH_X-1),  0, gridinfo, 0);
// //   fill_phase_circle(10, 0.75*(MESH_X-1), 0, gridinfo, 0);
// //   fill_phase_circle(10, (MESH_X-1),      0, gridinfo, 0);
// 
// 
// //   fill_phase_circle(10, 0, 0, gridinfo, NUMPHASES-1);
//   
// //   fill_phase_ellipse(50, 0.1,  -0.0, 0.5*(MESH_X-1), 0.5*(MESH_Y-1), gridinfo, 0);
// //   fill_phase_ellipse(50, 0.1,  -0.0, 0.5*(MESH_X-1), 0.5*(MESH_Y-1), gridinfo, NUMPHASES-1);
//   
//   fill_composition_cube(gridinfo);
//   writetofile_struct(gridinfo, 0);
// }
// 
// long assign_phase (double rand_phase) {
//   long i;
//   for (i=0; i < NUMPHASES-1; i++) {
//     if ((rand_phase >= i) && (rand_phase < (i+1)) ) {
//       return i;
//     }
//   }
// }
// int check_FLAG(int *FLAG_FILLED, long xo, long yo, long radius) {
//   long x,  y;
//   long gidy;
//   for (x =0; x < MESH_X; x++) {
//     for (y =0; y < MESH_Y; y++) {
//       gidy = x*MESH_Y + y;
//       if ((((x-xo)*(x-xo) + (y-yo)*(y-yo)) <= ((radius+2.0*epsilon)*(radius+2.0*epsilon)))) {
//         if (FLAG_FILLED[gidy] == 1) {
//           return 1;
//         }
//       }
//     }
//   }
//   return 0;
// }
// void assign_FLAG(int *FLAG_FILLED, long xo, long yo, long radius) {
//   long x,  y;
//   long gidy;
//   for (x =0; x < MESH_X; x++) {
//     for (y =0; y < MESH_Y; y++) {
//       gidy = x*MESH_Y + y;
//       if (((x-xo)*(x-xo) + (y-yo)*(y-yo)) <= ((radius+2.0*epsilon)*(radius+2.0*epsilon))) {
//        FLAG_FILLED[gidy] = 1;
//       }
//     }
//   }
// }
// void fill_random() {
//   long particlesize_bin[NUMBINS];
//   long numparticles_bin[NUMBINS];
//   int FLAG, *FLAG_FILLED;
//   
//   long fill_count;
//   long x, y, b;
//   long i;
//   long gidy;
//   
//   double rand_phase;
//   double rand_particle;
//   
//   FLAG_FILLED = (int*)malloc((MESH_X*MESH_Y)*sizeof(*FLAG_FILLED));
//   
//   for (x =0; x < MESH_X; x++) {
//     for (y =0; y < MESH_Y; y++) {
//       gidy = x*MESH_Y + y;
//       FLAG_FILLED[gidy] = 0;
//     }
//   }
//   
//   for (i=0; i< NUMBINS; i++) {
//     particlesize_bin[i] = (2*i+3)*0.5*BINSIZE;
//     x                   = particlesize_bin[i]*(0.7/25.0);
//     //Normal distribution................................................
// //     numparticles_bin[i] = floor((double)NUMPARTICLES*(double)(1.0/(sqrt(2.0*M_PI*MAXPARTICLE_SIZE*0.25)))*exp(-(x-MAXPARTICLE_SIZE*0.5)*(x-MAXPARTICLE_SIZE*0.5)/(2.0*MAXPARTICLE_SIZE*0.25)));
//     //...................................................................
//     numparticles_bin[i] = floor((double)NUMPARTICLES*(0.0087+0.32101*x-0.37669*pow(x,2.0)+0.16378*pow(x,3.0)-0.02991*pow(x,4.0)+0.00181*pow(x,5.0)));
//     
//     printf("%ld %ld %ld\n",i, x, numparticles_bin[i]);
//   }
//   srand(time(NULL));
//   for (i=0; i< NUMBINS; i++) {
//     fill_count=0;
//     if (numparticles_bin[i] > 0) {
//        while (fill_count <= numparticles_bin[i]) {
//           x = floor((MESH_X-1)*(double)(rand())/(double)RAND_MAX);
//           y = floor((MESH_Y-1)*(double)(rand())/(double)RAND_MAX);
//           
//           gidy = x*MESH_Y + y;
//           if ((fill_count <= numparticles_bin[i]) && (x < MESH_X) && (y<MESH_Y)) {
// //               FLAG = check_FLAG(FLAG_FILLED, x, y, particlesize_bin[i]);
// //               if ((FLAG == 0)) {
//                 rand_phase = floor((NUMPHASES-1)*(double)(rand())/(double)RAND_MAX);
//                 b = assign_phase(rand_phase);
// //                 fill_phase_circle(particlesize_bin[i], x,    y,    gridinfo, b);
//                 fill_phase_ellipse(particlesize_bin[i], 0.1, b*fabs(Rtheta) + Rtheta, x,    y,    gridinfo, b);
//                 assign_FLAG(FLAG_FILLED, x, y, particlesize_bin[i]);
//                 fill_count++;
//                 printf("%ld %ld %ld, %ld\n",i , fill_count, numparticles_bin[i], x);
// //               }
//           }
//        }
//     }
//     printf("%ld %ld\n", i, fill_count);
//   }
//   free(FLAG_FILLED);
// }
// 
// void find_numcubes(char *pattern, struct filling_type* filling_type_phase) {
//   long x;
//   long a;
//   
//   for (a=0; a < NUMPHASES-1; a++) {
//     filling_type_phase[a].NUMCUBES = 0;
//   }
//   
//   for (x=0; x < strlen(pattern); x++) {
//     for (a=0; a < NUMPHASES; a++) {
//       if ((pattern[x]) == '0'+ a) {
//         filling_type_phase[a].NUMCUBES++;
//         break;
//       }
//     }
//   }
// }
// void fillpattern(char *pattern, struct filling_type* filling_type_phase, long start_cube, long numperiods, struct variables* gridinfo) {
//   long x, a;
//   long periods =0;
//   for (periods=0; periods < numperiods; periods++) {
//     for (x=0; x < strlen(pattern); x++) {
//       for (a=0; a < NUMPHASES-1; a++) {
//         if (pattern[x] == ('0' + a)) {
//           fill_cube_parameters.x_start = start_cube;
//           fill_cube_parameters.x_end   = start_cube + filling_type_phase[a].length;
//           fill_cube_parameters.y_start = 0;
//           fill_cube_parameters.y_end   = 50;
//           fill_phase_cube(fill_cube_parameters, gridinfo, a);
//           start_cube += filling_type_phase[a].length+1;
//           break;
//         }
//       }
//     }
//   }
//   fill_phase_cube(fill_cube_parameters, gridinfo, NUMPHASES-1);
// }
// void tilting_fillpattern(char *pattern, struct filling_type* filling_type_phase, long start_cube, long numperiods, struct variables* gridinfo) {
//   long x, a;
//   long periods =0;
//   for (periods=0; periods < numperiods; periods++) {
//     for (x=0; x < strlen(pattern); x++) {
//       for (a=0; a < NUMPHASES-1; a++) {
//         if (pattern[x] == ('0' + a)) {
//           fill_cube_parameters.x_start = start_cube;
//           fill_cube_parameters.x_end   = start_cube + filling_type_phase[a].length;
//           fill_cube_parameters.y_start = 0;
//           fill_cube_parameters.y_end   = 50;
//           fill_phase_cube(fill_cube_parameters, gridinfo, a);
//           start_cube += filling_type_phase[a].length+1;
//           break;
//         }
//       }
//     }
//   }
//   fill_phase_cube(fill_cube_parameters, gridinfo, NUMPHASES-1);
// }
// void init_filling () {
//   filling_type_phase[0].volume_fraction = 0.5;
//   filling_type_phase[1].volume_fraction = 0.5;
//   filling_type_phase[2].volume_fraction = 0.5;
// //   filling_type_phase[3].volume_fraction = 0.33333333333;
//   
// //   filling_type_phase[0].NUMCUBES = 2;
// //   filling_type_phase[1].NUMCUBES = 2;
// //   filling_type_phase[2].NUMCUBES = 2;
// //   filling_type_phase[3].NUMCUBES = 1;
// }
// 
// 
