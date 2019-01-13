{
    "targets":[
        {
            "target_name":"addon",
            "sources":["*.cc", "method/*.cc"],
            "include_dirs":[
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}