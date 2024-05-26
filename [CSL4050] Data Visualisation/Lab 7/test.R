library(shiny)

ui <- fluidPage(
  titlePanel("My First Shiny App"),
  sidebarLayout(
    sidebarPanel(
      numericInput("n", "Number of observations:", 100)
    ),
    mainPanel(
      plotOutput("distPlot")
    )
  )
)

server <- function(input, output) {
  output$distPlot <- renderPlot({
    hist(rnorm(input$n), col = 'darkgray', border = 'white')
  })
}

shinyApp(ui = ui, server = server)
