# Load required libraries
library(shiny)
library(ggplot2)
library(readr)

# Load the dataset
wine_data <- read.csv("WineQT.csv")

# Define UI for the Shiny app
ui <- fluidPage(
  
  # Application title
  titlePanel("Interactive Scatter Plot"),
  
  # Sidebar layout with input and output definitions
  sidebarLayout(
    
    # Sidebar panel for inputs
    sidebarPanel(
      
      # Dropdown for selecting X-axis variable
      selectInput(inputId = "x_var",
                  label = "Select X-axis variable:",
                  choices = colnames(wine_data),
                  selected = "fixed acidity"),
      
      # Dropdown for selecting Y-axis variable
      selectInput(inputId = "y_var",
                  label = "Select Y-axis variable:",
                  choices = colnames(wine_data)[-length(colnames(wine_data))],
                  selected = "volatile acidity")
      
    ),
    
    # Main panel for displaying the plot
    mainPanel(
      
      # Displaying the scatter plot
      plotOutput(outputId = "scatter_plot")
    )
  )
)

# Define server logic
server <- function(input, output) {
  
  # Generate scatter plot based on user inputs
  output$scatter_plot <- renderPlot({
    
    # Extract selected variables from the dataset
    x_data <- wine_data[[input$x_var]]
    y_data <- wine_data[[input$y_var]]
    
    # Create scatter plot
    ggplot(data = wine_data, aes_string(x = input$x_var, y = input$y_var)) +
      geom_point() +
      labs(x = input$x_var, y = input$y_var, title = "Interactive Scatter Plot")
  })
}

# Run the application
shinyApp(ui = ui, server = server)
