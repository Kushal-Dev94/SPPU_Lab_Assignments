opt=1
while [ "$opt" -lt 6 ]
do
    echo -e "Choose one of the following\n1. Create a new Address Book\n2. View Records\n3. Insert new Records\n4. Delete a record\n5. Modify a record\n6. Exit"

    read opt
    case $opt in
    1)
        echo "Enter Filename:"
        read fileName
        if [ -e "$fileName" ]; then
            rm "$fileName"
        fi
        echo -e "NAME\tNUMBER\t\tADDRESS\n=======================================================\n" > "$fileName"
        cont=1
        while [ "$cont" -gt 0 ]
        do
            echo "Enter Name:"
            read name
            echo "Enter Phone Number of $name:"
            read number
            echo "Enter Address of $name:"
            read address
            echo "$name\t$number\t\t$address" >> "$fileName"
            echo "Enter 0 to stop, 1 to enter next:"
            read cont
        done
        ;;
        
    2)
        if [ -e "$fileName" ]; then
            cat "$fileName"
        else
            echo "No Address Book found."
        fi
        ;;
        
    3)
        if [ -e "$fileName" ]; then
            echo "\nEnter Name"
            read name
            echo "Enter Phone no of $name"
            read number
            echo "Enter Address of $name"
            read address
            echo "$name\t$number\t\t$address" >> "$fileName"
        else
            echo "No Address Book found. Create a new one first (Option 1)."
        fi
        ;;
        
    4)
        if [ -e "$fileName" ]; then
            echo "Delete a record\nEnter Name / Phone Number"
            read pattern
            grep -v "$pattern" "$fileName" > temp
            mv temp "$fileName"
        else
            echo "No Address Book found."
        fi
        ;;
        
    5)
        if [ -e "$fileName" ]; then
            echo "Modify a record\nEnter Name / Phone Number"
            read pattern
            echo "Enter new Name:"
            read newName
            echo "Enter new Phone Number:"
            read newNumber
            echo "Enter new Address:"
            read newAddress
            sed -i "s/^$pattern.*/$newName\t$newNumber\t\t$newAddress/" "$fileName"
        else
            echo "No Address Book found."
        fi
        ;;
        
    6)
        echo "Exiting..."
        exit 0
        ;;
        
    *)
        echo "Invalid option. Please enter a number between 1 and 6."
        ;;
    esac
done

