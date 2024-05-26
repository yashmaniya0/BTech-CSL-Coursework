library(shiny)
library(ggplot2)
library(dplyr)
library(tidyr)

# Read the data
thyroid_data <- read.csv("./new-thyroid.data", header = TRUE)

# Define UI
ui <- fluidPage(
  
  titlePanel("Thyroid Data Visualization"),
  
  sidebarLayout(
    sidebarPanel(
      # Bin size input for histograms
      sliderInput("bin_size", "Bin Size", min = 1, max = 30, value = 10),
      
      # Color picker inputs for histograms
      selectInput("hist_color", "Histogram Color", 
                  choices = c("skyblue", "lightgreen", "lightpink", "lavender", "lightgrey")),
      
      # X axis selection for scatter plot
      selectInput("x_var", "X-axis Variable", choices = names(thyroid_data)[-1])
    ),
    
    mainPanel(
      # Histogram plots
      plotOutput("histogram1"),
      plotOutput("histogram2"),
      plotOutput("histogram3"),
      plotOutput("histogram4"),
      plotOutput("histogram5"),
      plotOutput("histogram6"),
      
      # Scatter plot
      plotOutput("scatter_plot")
    )
  )
)

# Define server logic
server <- function(input, output) {
  
  # Reactive function for filtered data based on class selection
  filtered_data <- reactive({
    filter(thyroid_data)
  })
  
  # Histogram plots
  output$histogram1 <- renderPlot({
    ggplot(thyroid_data, aes(x = !!sym(input$x_var), fill = !!input$hist_color)) +
      geom_histogram(binwidth = input$bin_size, color = "black") +
      scale_fill_manual(values = input$hist_color) +
      labs(title = paste("Histogram of", input$x_var))
  })
  
  # Repeat similar code blocks for other histograms
  
  # Scatter plot
  output$scatter_plot <- renderPlot({
    ggplot(filtered_data(), aes_string(x = input$x_var)) +
      geom_point() +
      labs(title = paste("Scatter Plot of", input$x_var), x = input$x_var)
  })
}

# Run the application
shinyApp(ui = ui, server = server)
