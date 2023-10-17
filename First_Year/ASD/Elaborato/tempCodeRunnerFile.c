
    for (int i = 0; i < total; i++)
    {
        deleteList(&box_data[i].head_adjacency_list);
        deleteList(&box_data_top_sort[i].head_adjacency_list);
    }

    //close currently open input file
    fclose(fptr);
    return 0;
}