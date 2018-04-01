/* algoritmo quicksort*/

/*ALGORITMO ADAPTADO AL BENCHMARK*/

   void qs(int *lista, int first, int last,Experiment * experiment){
      int i= first, j = last, pivote;
      pivote=lista[(first + last)/2];
      do{
         while(compare(lista[i]<pivote && i< last),experiment){
            i++;
         }
         while(compare(lista[j] > pivote && j > first), experiment){
            j--;
         }
         if(i<=j){
            swap(lista[i],lista[j],experiment);
            i++; j--;
         }
       }   while(i<=j);
       if(first<j){
          qs(lista,first,j,experiment);
       }
       if(i<last){
          qs(lista,i,last,experiment);
       }
   }
     void quickshort(int *lista, int N,Experiment * experiment){ /* función para pasarle a quicksort la tabla a ordenar*/
      int first, last;
      first = 0;
      last = N-1;
      qs(lista,first, last, experiment);
   
   }


 
   /* ALGORITMO SIN ADAPTAR AL BENCHMARK*/
   /*ALGORITMO PARA PRUEBAS*/
   
   /*void qs(int *lista, int first, int last){
      int i= first, j = last, pivote, aux;
      pivote=lista[(first + last)/2];
      do{
         while(lista[i]<pivote && i< last){
            i++;
         }
         while(lista[j] > pivote && j > first){
            j--;
         }
         if(i<=j){
            aux= lista[i];
            lista[i]=lista[j];
            lista[j]=aux;
            i++; j--;
         }
       }   while(i<=j);
       if(first<j){
          qs(lista,first,j);
       }
       if(i<last){
          qs(lista,i,last);
       }
   }
     void quickshort(int *lista, int N){ 
      int first, last;
      first = 0;
      last = N-1;
      qs(lista,first, last);
   
   }
   
   
    #include <stdio.h>
   int main(){
   int A[100] ={88,
 30,100, 19, 24, 94, 79, 86, 60, 96,  2, 26, 46, 18,  8, 98, 45, 80, 32, 71, 23, 14, 75, 82, 54, 72, 34, 73, 56,  3, 31, 55, 67, 90, 12, 91, 69, 36, 11, 48, 59, 83,13, 76, 93, 92, 25, 28, 15, 47, 63, 49,  5, 37, 53, 97, 16, 38, 66, 21, 77, 52, 84, 65, 17, 51, 22, 74, 29, 89, 42, 62, 39, 87, 35, 68, 40,  7, 41, 85, 44,  1, 95,99,  4, 57, 43, 27, 61, 10, 70, 33, 64, 58,  6, 50, 81, 78, 20,  9};
 int B[1000]={888, 37, 702, 963, 514, 218, 732, 178, 990, 31, 93, 916, 225, 238, 570, 712, 459, 551, 867, 84, 788, 738, 941, 451, 69, 344, 905, 121, 252, 35, 470, 122, 853, 761, 364, 862, 163, 813, 709, 958, 695, 856, 375, 86, 718, 155, 347, 571, 503, 845, 516, 151, 94, 633, 642, 656, 901, 57, 729, 672, 263, 185, 275, 965, 336, 661, 699, 132, 46, 595, 531, 620, 108, 735, 972, 311, 208, 528, 492, 95, 822, 520, 376, 618, 206, 407, 650, 397, 655, 694, 670, 494, 203, 285, 172, 435, 475, 504, 819, 606, 700, 900, 134, 907, 167, 101, 740, 924, 74, 836, 959, 543, 278, 688, 908, 886, 156, 911, 649, 626, 99, 974, 584, 624, 644, 736, 188, 557, 478, 577, 511, 381, 519, 939, 75, 567, 189, 1, 871, 604, 787, 296, 2, 98, 498, 969, 850, 913, 552, 766, 337, 393, 896, 713, 730, 768, 7, 200, 622, 65, 385, 368, 532, 116, 455, 838, 952, 715, 841, 857, 806, 241, 442, 705, 750, 153, 833, 10, 127, 973, 301, 979, 118, 191, 926, 143, 780, 934, 698, 510, 119, 887, 967, 96, 829, 485, 521, 753, 964, 960, 493, 114, 264, 286, 85, 366, 77, 610, 251, 357, 714, 894, 322, 843, 279, 54, 540, 261, 304, 139, 789, 490, 931, 689, 998, 673, 199, 802, 332, 932, 933, 244, 724, 300, 79, 194, 345, 816, 481, 227, 373, 330, 310, 27, 664, 222, 723, 820, 182, 457, 117, 809, 247, 651, 409, 881, 9, 754, 515, 220, 940, 797, 291, 994, 177, 910, 419, 73, 892, 318, 588, 62, 546, 68, 431, 280, 679, 612, 977, 903, 733, 748, 693, 47, 800, 422, 637, 378, 15, 22, 168, 499, 128, 115, 631, 558, 495, 24, 865, 807, 675, 669, 772, 782, 795, 508, 815, 603, 586, 657, 55, 40, 859, 579, 792, 830, 268, 549, 316, 891, 171, 534, 256, 627, 923, 545, 784, 727, 52, 63, 137, 426, 988, 387, 213, 866, 954, 984, 401, 597, 272, 737, 105, 333, 312, 161, 205, 847, 925, 858, 58, 744, 111, 274, 682, 776, 917, 328, 884, 441, 763, 87, 717, 120, 219, 755, 491, 319, 769, 341, 668, 505, 144, 21, 953, 876, 424, 67, 765, 421, 899, 136, 145, 400, 258, 501, 710, 783, 987, 447, 19, 928, 801, 663, 113, 985, 420, 59, 103, 665, 36, 355, 524, 8, 371, 640, 292, 335, 438, 576, 560, 641, 970, 955, 60, 869, 367, 398, 102, 918, 64, 596, 599, 131, 97, 38, 41, 352, 864, 882, 412, 391, 239, 198, 914, 277, 660, 608, 828, 377, 652, 951, 746, 936, 183, 799, 133, 747, 321, 223, 893, 109, 995, 217, 904, 142, 449, 186, 283, 687, 154, 271, 29, 874, 785, 883, 966, 756, 739, 158, 448, 44, 482, 436, 875, 938, 527, 666, 582, 680, 91, 745, 383, 266, 104, 982, 581, 230, 770, 129, 464, 303, 643, 439, 170, 535, 33, 248, 547, 945, 297, 734, 430, 181, 349, 465, 468, 539, 233, 138, 811, 902, 112, 565, 625, 458, 697, 45, 513, 306, 589, 775, 175, 607, 427, 568, 236, 842, 246, 635, 415, 257, 380, 929, 334, 157, 563, 948, 912, 83, 284, 719, 971, 790, 53, 701, 537, 315, 922, 591, 681, 759, 483, 13, 538, 453, 569, 413, 873, 791, 578, 331, 615, 831, 130, 566, 512, 722, 192, 854, 473, 741, 823, 43, 749, 518, 379, 477, 374, 825, 314, 496, 454, 363, 703, 583, 5, 949, 423, 76, 935, 289, 906, 978, 437, 757, 957, 358, 592, 648, 224, 824, 976, 255, 897, 580, 989, 434, 920, 51, 49, 550, 305, 692, 996, 472, 486, 944, 204, 659, 861, 564, 983, 327, 361, 594, 720, 573, 307, 234, 250, 11, 762, 980, 667, 613, 146, 930, 388, 981, 752, 265, 593, 169, 553, 794, 846, 942, 299, 852, 359, 396, 166, 12, 487, 529, 290, 562, 141, 678, 542, 725, 323, 207, 937, 522, 895, 382, 556, 860, 880, 339, 164, 428, 269, 351, 295, 804, 872, 992, 372, 630, 827, 210, 617, 221, 187, 417, 229, 25, 798, 384, 530, 165, 4, 17, 469, 480, 180, 414, 685, 403, 611, 201, 16, 259, 639, 497, 793, 686, 450, 23, 369, 3, 202, 149, 915, 425, 215, 432, 731, 598, 778, 211, 471, 921, 140, 260, 743, 460, 190, 707, 353, 647, 947, 152, 416, 868, 728, 751, 313, 810, 548, 605, 760, 855, 890, 575, 273, 462, 106, 991, 863, 61, 817, 410, 844, 390, 654, 645, 943, 619, 779, 325, 623, 837, 389, 342, 110, 885, 814, 662, 526, 267, 92, 691, 125, 851, 600, 826, 402, 839, 671, 572, 777, 997, 849, 601, 927, 245, 148, 231, 587, 962, 405, 81, 674, 32, 476, 488, 781, 832, 70, 326, 365, 1000, 14, 147, 561, 677, 408, 411, 466, 708, 176, 26, 919, 34, 467, 506, 456, 479, 196, 356, 999, 71, 42, 690, 716, 840, 329, 808, 370, 658, 590, 30, 50, 946, 507, 993, 609, 554, 523, 721, 237, 6, 444, 317, 302, 360, 80, 354, 877, 818, 240, 961, 742, 696, 474, 968, 243, 771, 544, 704, 636, 324, 502, 66, 634, 232, 452, 500, 209, 179, 293, 346, 282, 445, 89, 288, 764, 796, 39, 676, 446, 489, 440, 20, 348, 262, 18, 216, 726, 525, 616, 340, 159, 602, 270, 683, 909, 706, 986, 350, 646, 173, 48, 870, 253, 758, 773, 362, 632, 461, 786, 629, 135, 517, 214, 150, 88, 242, 541, 294, 536, 276, 298, 950, 160, 429, 72, 621, 463, 406, 320, 821, 90, 805, 249, 197, 124, 638, 585, 308, 628, 889, 898, 78, 254, 684, 767, 126, 812, 848, 395, 574, 834, 56, 162, 212, 287, 226, 399, 193, 484, 614, 174, 803, 835, 235, 555, 107, 195, 338, 774, 653, 228, 443, 386, 975, 559, 394, 404, 879, 100, 956, 711, 309, 392, 533, 82, 509, 123, 281, 433, 184, 878, 343, 418, 28};
 int C[8]={44 ,55,12,42,94,18,6,67};
   int k;
   quickshort(B,1000);
   for(k=0;k<1000;k++){
  int a=B[k];
      printf("%i\n",a);
   }
   
   } */
   
   
   
