cmd_/home/haoranx98/code/my_kernel_module/Module.symvers := sed 's/ko$$/o/' /home/haoranx98/code/my_kernel_module/modules.order | scripts/mod/modpost -m -a   -o /home/haoranx98/code/my_kernel_module/Module.symvers -e -i Module.symvers   -T -
