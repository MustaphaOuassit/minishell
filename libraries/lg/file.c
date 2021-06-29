int main()
{
    char *line;
    while(1)
    {
        write(1,"-> mishell ",ft_strlen("-> mishell "));
        get_next_line(0,&line);
    }
    return(0);
}