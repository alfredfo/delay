project('delay', 'c',
	meson_version: '>=1.3.0',
	default_options: ['c_std=c17'])

src = []
incdir = []

subdir('src')
delay = executable('delay', src, include_directories: incdir)

prog_objcopy = find_program('objcopy')
input_bfdname = meson.get_external_property('input_bfdname')
custom_target('delay_srecord',
	      build_by_default: true,
	      output: 'delay.s19',
	      input: delay,
	      command : [prog_objcopy, '-I'+input_bfdname,
			         '@INPUT@', '-Osrec', '@OUTPUT@'])
