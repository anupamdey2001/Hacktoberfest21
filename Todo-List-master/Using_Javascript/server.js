const express=require('express');
const bodyParser=require('body-parser');
const mongoose=require('mongoose');
const _ =require('lodash');

const app=express();

app.use(bodyParser.urlencoded({extended:true}));
app.use(express.static("public"));

app.set('view engine','ejs');


//Now using Mongoose to store Data

mongoose.connect("mongodb+srv://admin-aditya:Aditya2018@cluster0.nbslt.mongodb.net/todolistDB", {useNewUrlParser: true});

const itemsSchema = {
    name : String
};

const Item = mongoose.model("Item",itemsSchema);

const item1 = new Item({
    name: "This is my ToDo List"
});

const item2 = new Item({
    name: "Hit + to add new task"
});

const item3 = new Item({
    name:"<-Click on the checkBox to delete any task "
});

const defaultItems= [item1, item2, item3];

const listSchema ={
    name : String,
    items: [itemsSchema]
};

const List= mongoose.model("List",listSchema);

app.get("/",(req,res)=>
{
    Item.find({},(err,foundItems)=>{
        //console.log(findItems);

        if(foundItems.length===0)
        {
            Item.insertMany(defaultItems,function(err){
                if(err)
                {
                    console.log(err);
                }
                else
                {
                    console.log("Success!");
                }
            });
            res.redirect("/");
        }
        else
        {
            res.render("list", {listTitle: "Today", newListItems: foundItems});
        }
    });

    let today=new Date();

    let options=
    {
        weekday:"long",
        day:"numeric",
        month:"long"
    };

    let day= today.toLocaleDateString("en-US",options);
});

app.post("/",(req,res)=>
{

    const itemName = req.body.newItem;
    const listName = req.body.list;

    const item = new Item({
        name : itemName
    });

    if(listName==="Today")
    {
        item.save();
        res.redirect("/");
    }
    else
    {
        List.findOne({name:listName},function(err,foundList){
            foundList.items.push(item);
            foundList.save();
            res.redirect("/" + listName);
        });
    }
});

app.post("/delete",(req,res)=>{

    const checkedItemId= req.body.checkbox;
    const listName=req.body.listName;

    if(listName==="Today")
    {
        Item.findByIdAndRemove(checkedItemId,function(err){
            if(!err)
            {
                res.redirect("/");
            }
        });
    }

    else
    {
        List.findOneAndUpdate({name:listName},{$pull:{items: {_id: checkedItemId}}}, function(err,foundList)
        {
            if(!err)
            {
                res.redirect("/"+listName);
            }
        });
    }
});

app.get("/:customListName",function(req,res){
    const customListName= _.capitalize(req.params.customListName);

    List.findOne({name:customListName},function(err,foundList){
        if(!err){
            if(!foundList)
                {
                //console.log("Doesn't exist !");  therefore create a new List

                const list = new List({
                    name: customListName,
                    items: defaultItems
                });
                list.save();
                res.redirect("/"+ customListName);
            }
            else
            {
                // console.log("Exists!");  therefore show an existing list
                res.render("list",{listTitle: foundList.name, newListItems:foundList.items})
            }
        }
    })
});



app.get("/about",(req,res)=>{
    res.render("about");
});


let port=process.env.PORT;
if(port==null || port=="")
{
    port=3000;
}
app.listen(port,()=>{
    console.log("Server is running");
})