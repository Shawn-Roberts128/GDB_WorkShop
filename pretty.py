class PrintGList(gdb.Command):
    """print Glib Glist: wzd_print_glist list objecttype

        Iterate through the list of nodes in a GList, and display
        a human-readable form of the objects."""
    def __init__(self):
        gdb.Command.__init__(self, "wzd_print_glist", gdb.COMMAND_DATA, gdb.COMPLETE_SYMBOL, True)
    def invoke(self, arg, from_tty):
        arg_list = gdb.string_to_argv(arg)
        if len(arg_list) < 2:
            print("usage: wzd_print_glist list objecttype")
            return
        l = gdb.parse_and_eval(arg_list[0])
        if l.type.code != gdb.lookup_type('GList').pointer().code:
            print( "{} is not a GList*".format( arg_list[0]))
            return

        while l:
            self._print_node(l, t)
            l = l['next']a
    def _print_node
            try:
                t = gdb.lookup_type(typename)
            except RuntimeError, e:
                print ("type {} not found".format( arg_list[1]))
                return
