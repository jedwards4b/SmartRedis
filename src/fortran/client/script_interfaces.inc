interface
  subroutine get_script_c( c_client, key, key_length, script, script_length) bind(c,name="get_script")
    use iso_c_binding, only : c_ptr, c_char, c_size_t
    type(c_ptr), value,            intent(in)    :: c_client   !< Initialized SILC client
    character(kind=c_char),        intent(in)    :: key(*)     !< The key to use to place the script
    integer(kind=c_size_t), value, intent(in)    :: key_length !< The length of the key c-string, excluding null
    type(c_ptr),                   intent(inout) :: script      !< The script as a continuous buffer
    integer(kind=c_size_t),        intent(  out) :: script_length !< Length of the script buffer c-string
  end subroutine get_script_c
end interface
interface
  subroutine set_script_from_file_c( c_client, key, key_length, device, device_length, &
                                     script_file, script_file_length) bind(c,name="set_script_from_file")
    use iso_c_binding, only : c_ptr, c_size_t,  c_char
    type(c_ptr), value,            intent(in) :: c_client          !< Initialized SILC client
    character(kind=c_char),        intent(in) :: key(*)            !< The key to use to place the script
    integer(kind=c_size_t), value, intent(in) :: key_length        !< The length of the key c-string, excluding null
    character(kind=c_char),        intent(in) :: device(*)         !< The name of the device (CPU, GPU, GPU:0, GPU:1...)
    integer(kind=c_size_t), value, intent(in) :: device_length     !< The length of the device name c-string, excluding
                                                                   !! null terminating character
    character(kind=c_char),        intent(in) :: script_file(*)     !< The file storing the script
    integer(kind=c_size_t), value, intent(in) :: script_file_length !< The length of the file name c-string, excluding
                                                                   !! null terminating character
  end subroutine set_script_from_file_c
end interface

interface
  subroutine set_script_c( c_client, key, key_length, device, device_length, script, script_length ) &
      bind(c, name="set_script")
    use iso_c_binding, only : c_ptr, c_size_t,  c_char
    type(c_ptr), value,            intent(in) :: c_client          !< Initialized SILC client
    character(kind=c_char),        intent(in) :: key(*)            !< The key to use to place the script
    integer(kind=c_size_t), value, intent(in) :: key_length        !< The length of the key c-string, excluding null
    character(kind=c_char),        intent(in) :: device(*)         !< The name of the device (CPU, GPU, GPU:0, GPU:1...)
    integer(kind=c_size_t), value, intent(in) :: device_length     !< The length of the device name c-string, excluding
                                                                   !! null terminating character
    character(kind=c_char),        intent(in) :: script(*)     !< The file storing the script
    integer(kind=c_size_t), value, intent(in) :: script_length !< The length of the file name c-string, excluding
                                                                   !! null terminating character
  end subroutine set_script_c
end interface

interface
  subroutine run_script_c(c_client, key, key_length, func, func_length, inputs, input_lengths, n_inputs, &
                         outputs, output_lengths, n_outputs) bind(c, name="run_script")
    use iso_c_binding, only : c_ptr, c_size_t, c_char
    type(c_ptr), value,            intent(in) :: c_client       !< Initialized SILC client
    character(kind=c_char),        intent(in) :: key(*)         !< The key to use to place the script
    integer(kind=c_size_t), value, intent(in) :: key_length     !< The length of the key c-string, excluding null
    character(kind=c_char),        intent(in) :: func(*)        !< The name of the function in the script to call
    integer(kind=c_size_t), value, intent(in) :: func_length    !< The length of the function c-string, excluding
                                                                !! null terminating character
    type(c_ptr),            value, intent(in) :: inputs         !< One or more names of script input nodes (TF scripts)
    type(c_ptr),            value, intent(in) :: input_lengths  !< The length of each input name c-string, excluding
                                                                !! null terminating character
    integer(kind=c_size_t), value, intent(in) :: n_inputs       !< The number of inputs
    type(c_ptr),            value, intent(in) :: outputs        !< One or more names of script output nodes
                                                                !! (TF scripts)
    type(c_ptr),            value, intent(in) :: output_lengths !< The length of each output name c-string,
                                                                !! excluding null terminating character
    integer(kind=c_size_t), value, intent(in) :: n_outputs      !< The number of outputs

  end subroutine run_script_c
end interface